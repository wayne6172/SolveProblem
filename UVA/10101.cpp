#include <stdio.h>
#include <stdlib.h>

void f(unsigned long long num){
    if(num>=10000000){
        f(num/10000000);
        num%=10000000;
        printf(" kuti");
    }
    if(num/100000%100)printf(" %d lakh",num/100000%100);
    if(num/1000%100)printf(" %d hajar",num/1000%100);
    if(num/100%10)printf(" %d shata",num/100%10);
    if(num%100)printf(" %d",num%100 );
}

int main(int argc, char const *argv[]) {
    unsigned long long num,test=0;
    while(scanf("%llu",&num)!=EOF){
        printf("%4d.",++test);
        if(num==0)printf(" 0");
        else f(num);
        printf("\n");
    }
    return 0;
}
