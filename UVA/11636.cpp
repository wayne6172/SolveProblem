#include <cstdio>


int main(int argc, char const *argv[])
{
    int n,t = 0;
    while(~scanf("%d",&n) && n > 0){
        int sum = 0, is = 0;
        while(n != 1){
            if(n % 2 == 1){
                is = 1;
            }
            sum++;
            n /= 2;
        }
        if(is == 1){
            sum++;
        }       
        printf("Case %d: %d\n",++t,sum);
    }

    return 0;
}