#include <x86intrin.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define UNROLL (4)
#define BLOCKSIZE 64

// gcc -mavx -O3 -fopenmp DGEMM.c

void dgemm(int n, double* A, double* B, double *C){
    int i,j,k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            double cij = 0;
            for(k = 0; k < n; k++)
                cij += A[i + k * n] * B[k + j * n];
            C[i + j * n] = cij;
        }
}

void dgemm_P(int n, double* A, double* B, double *C){
    int i,j,k;

    for(i = 0; i < n; i += 4)
        for(j = 0; j < n; j++){
            __m256d c0 = _mm256_load_pd(C+i+j*n);
            for(k = 0; k < n; k++)
                c0 = _mm256_add_pd(c0,_mm256_mul_pd(_mm256_load_pd(A+i+k*n),_mm256_broadcast_sd(B+k+j*n)));
            
            _mm256_store_pd(C+i+j*n, c0);
        }
            
}

void degemm_P2(int n, double* A, double* B,double *C){
    int i,j,k,x;

    for(i = 0; i < n; i += UNROLL * 4)
        for(j = 0; j < n; j++){
            __m256d c[UNROLL];
            for(x = 0; x < UNROLL; x++)
                c[x] = _mm256_load_pd(C+i+x*4+j*n);

            for(k = 0; k < n; k++){
                __m256d b = _mm256_broadcast_sd(B+k+j*n);
                for(x = 0; x < UNROLL; x++)
                    c[x] = _mm256_add_pd(c[x],_mm256_mul_pd(_mm256_load_pd(A+n*k+x*4+i),b));
            }
            
            for(x = 0; x < UNROLL; x++)
                _mm256_store_pd(C+i+x*4+j*n,c[x]);
        }
}

void do_block(int n,int si,int sj,int sk,double *A,double *B,double *C){
    int i,j,k,x;

    for(i = si; i < si + BLOCKSIZE; i += UNROLL * 4)
        for(j = sj; j < sj + BLOCKSIZE; j++){
            __m256d c[4];
            for(x = 0; x < UNROLL; x++)
                c[x] = _mm256_load_pd(C+i+x*4+j*n);

            for(k = sk; k < sk + BLOCKSIZE; k++){
                __m256d b = _mm256_broadcast_sd(B+k+j*n);
                for(x = 0; x < UNROLL; x++)
                    c[x] = _mm256_add_pd(c[x],_mm256_mul_pd(_mm256_load_pd(A+n*k+x*4+i),b));
            }
            
            for(x = 0; x < UNROLL; x++)
                _mm256_store_pd(C+i+x*4+j*n,c[x]);
        }
}

void dgemm_P3(int n, double* A, double* B,double *C){
    int sj,si,sk;

    for(sj = 0; sj < n; sj += BLOCKSIZE)
        for(si = 0; si < n; si += BLOCKSIZE)
            for(sk = 0; sk < n; sk += BLOCKSIZE)
                do_block(n,si,sj,sk,A,B,C);
}

void dgemm_P4(int n, double* A, double* B,double *C){
    int sj,si,sk;

    #pragma omp parallel for
    for(sj = 0; sj < n; sj += BLOCKSIZE)
        for(si = 0; si < n; si += BLOCKSIZE)
            for(sk = 0; sk < n; sk += BLOCKSIZE)
                do_block(n,si,sj,sk,A,B,C);
}

int compare(double *C, double *C1, int size){
    int i = 0;
    for(; i < size; i++)
        if(C[i] != C1[i])
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    clock_t stop, start;
    int MAX = 0;

    FILE *fpA = fopen("dataA.bin","rb"), *fpB = fopen("dataB.bin","rb");
    
    if(fpA == NULL || fpB == NULL)
        return -1;
    
    fread(&MAX,sizeof(int),1,fpA);
    fseek(fpB,sizeof(int),SEEK_SET);

    double *A = (double *)malloc(sizeof(double) * MAX * MAX);
    double *B = (double *)malloc(sizeof(double) * MAX * MAX);
    double *C = (double *)calloc(MAX * MAX, sizeof(double));
    double *C1 = (double *)calloc(MAX * MAX, sizeof(double));
    double *C2 = (double *)calloc(MAX * MAX, sizeof(double));
    double *C3 = (double *)calloc(MAX * MAX, sizeof(double));
    double *C4 = (double *)calloc(MAX * MAX, sizeof(double));

    fread(A,sizeof(double) * MAX * MAX, 1, fpA);
    fread(B,sizeof(double) * MAX * MAX, 1, fpB);
    
    start = clock();

    dgemm(MAX,A,B,C);

    stop = clock();

    printf("not use: %.3lf\n",((double)stop - start) / CLOCKS_PER_SEC);

    //------------------------------------//

    start = clock();

    dgemm_P(MAX,A,B,C1);

    stop = clock();

    printf("use1 : %.3lf\n",((double)stop - start) / CLOCKS_PER_SEC);

    //------------------------------------//

    start = clock();

    degemm_P2(MAX,A,B,C2);

    stop = clock();

    printf("use2 : %.3lf\n",((double)stop - start) / CLOCKS_PER_SEC);


    //------------------------------------//

    start = clock();

    dgemm_P3(MAX,A,B,C3);

    stop = clock();

    printf("use3 : %.3lf\n",((double)stop - start) / CLOCKS_PER_SEC);

    //------------------------------------//*/

    start = clock();

    dgemm_P4(MAX,A,B,C4);

    stop = clock();

    printf("use4 : %.3lf\n",((double)stop - start) / CLOCKS_PER_SEC);

    fclose(fpA);
    fclose(fpB);

    free(A);
    free(B);
    free(C);
    free(C1);
    free(C2);
    free(C3);
    free(C4);

	system("pause");
    return 0;
}


