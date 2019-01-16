#include <cstdio>

unsigned r(unsigned B,unsigned P, unsigned M){
    if(P == 0)return 1 % M;
    else if(P == 1)return B % M;
    else {
        unsigned ans = r(B,P / 2, M);
        if(P % 2)return ((ans * ans ) % M * (B % M)) % M;
        else return (ans * ans) % M;
    }
}

int main(int argc, char const *argv[])
{
    unsigned B,P,M;
    while(scanf("%d%d%d",&B,&P,&M)!=EOF){
        printf("%u\n",r(B,P,M));
    }

    return 0;
}
