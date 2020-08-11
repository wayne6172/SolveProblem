#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fpA = fopen("dataA.bin","wb");
    FILE *fpB = fopen("dataB.bin","wb");
    
    if(argc < 2){
        printf("error\n");
        return -1;
    }

    int MAX = atoi(argv[1]);
    if(MAX <= 0 || MAX > 2560){
        printf("error\n");
        return -1;
    }

    double *A = malloc(sizeof(double) * MAX * MAX);
    double *B = malloc(sizeof(double) * MAX * MAX);

    int i,j;
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            A[i * MAX + j] = (double)rand() / RAND_MAX * 500; // 0 ~ 500
    
    printf("%d\n",MAX);
    fwrite(&MAX,sizeof(int),1,fpA);
    fwrite(A,sizeof(double) * MAX * MAX, 1, fpA);
    fclose(fpA);

    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            B[i * MAX + j] = (double)rand() / RAND_MAX * 500; // 0 ~ 500

    fwrite(&MAX,sizeof(int),1,fpB);
    fwrite(B,sizeof(double) * MAX * MAX, 1, fpB);
    fclose(fpB);

    free(A);
    free(B);

    return 0;
}
