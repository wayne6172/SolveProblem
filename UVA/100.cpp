// correct

#include <cstdio>

int f(int n){
    if(n == 1)return 1;
    else if(n % 2)return f(3 * n + 1) + 1;
    else return f(n / 2) + 1;
}

int main(int argc, char const *argv[])
{
    int a,b,i,j,max,sum;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a > b){
            j = a;
            i = b;
        }
        else {
            i = a;
            j = b;
        }

        max = 0;
        for(int t = i; t <= j; t++){
            sum = f(t);
            if(sum > max)max = sum;
        }

        printf("%d %d %d\n",a,b,max);
    }
    return 0;
}
