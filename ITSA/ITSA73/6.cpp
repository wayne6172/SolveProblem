#include <cstdio>
#include <cstdlib>
#include <cmath>

int cmp(const void *a,const void *b){
    return *(int *)b - *(int *)a;
}

int main(int argc, char const *argv[])
{
    int t;
    int n;
    int array[10000], sum;
    double space, now;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);

        space = 1 / (double)n * 100;

        for(int i = 0; i < n; i++)
            scanf("%d",&array[i]);

        qsort(array,n,sizeof(int),cmp);

        now = 0;
        sum = 0;
        for(int i = 0; i < n; i++, now += space){
            double temp;

            if(i > 0 && array[i - 1] == array[i]){
                int j = i - 1;
                while(j - 1 >= 0 && array[j - 1] == array[j])j--;

                temp = (int)ceil(space * j);
            }
            else temp = (int)ceil(now);
             
            
            if(temp <= 10)
                sum += (int)ceil(array[i] * 0.4);
            else if(temp <= 30)
                sum += (int)ceil(array[i] * 0.3);
            else if(temp <= 60)
                sum += (int)ceil(array[i] * 0.2);
            else if(temp <= 80)
                sum += (int)ceil(array[i] * 0.1);
            //printf("%lf %lf\n",temp ,now);
        }
        printf("%d\n",sum);
    }

    return 0;
}
