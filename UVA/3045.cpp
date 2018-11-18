// Correct

#include <cstdio>

int main(int argc, char const *argv[])
{
    int n,i,j,t,sum;
    while(scanf("%d",&n) && n){
        sum = 0, i = 1, t = 1;
        while(t <= n){
            for(j = 1; j <= i && t <= n; j++, t++){
                sum += i;
            }
            i++;
        }
        printf("%d %d\n",n,sum);
    }

    return 0;
}
