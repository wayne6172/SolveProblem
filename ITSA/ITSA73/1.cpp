#include <cstdio>
#include <cstdlib>

int cmp(const void *a, const void *b){
    int x = *(int *)a;
    int y = *(int *)b;
    int xS = 0, yS = 0;

    while(x != 0){
        xS += x % 10;
        x /= 10;
    }

    while(y != 0){
        yS += y % 10;
        y /= 10;
    }

    if(xS < yS)return -1;
    else if(xS > yS)return 1;
    else return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
    int N;
    int array[10];
    scanf("%d",&N);

    for(int i = 0; i < N; i++)
        scanf("%d",&array[i]);

    qsort(array,N,sizeof(int),cmp);

    for(int i = 0; i < N; i++){
        printf("%d",array[i]);
        if(i == N - 1)printf("\n");
        else printf(" ");
    }

    return 0;
}
