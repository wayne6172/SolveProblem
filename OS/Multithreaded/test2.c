#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define MAX 90000000

int array[MAX];

int main(){
    srand(5000);

    long long int sum = 0, i;

    for(i = 0; i < MAX; i++)
        array[i] = rand() % 10000;
    
    #pragma omp parallel for
    for(i = 0; i < MAX; i++)
        sum += array[i];
    
    printf("%lld\n",sum);
}