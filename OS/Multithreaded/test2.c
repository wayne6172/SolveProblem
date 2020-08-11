#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define MAX 90000000

int array[MAX];

int main(){
    srand(5000);

    long long int sum = 0, i, k, space = MAX / 1000;
    clock_t stop, start;

    start = clock();
    for(i = 0; i < MAX; i++)
        array[i] = rand() % 10000;
    stop = clock();
    
    #pragma omp parallel
    {
        printf("I am a parallel region.\n");
    }

    

    #pragma omp parallel for
    for(k = 0; k < 1000; k++){
        for(i = k * space; i < (k + 1) * space; i++)
            sum += array[i];
    }

    
    
    printf("%lld %.3lf\n",sum,((double)stop - start) / CLOCKS_PER_SEC);
}