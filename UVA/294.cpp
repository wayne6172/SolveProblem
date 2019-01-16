#include <cstdio>
#define MAX 10000*10000

char isPrime[MAX + 1];
int prime[10000 + 1],length = 0;

int find(int n){
    if(n == 1)return 1;
    
    int total = 1;

    for(int i = 0; i < length; i++){
        int tmp = 1;
        while(n % prime[i] == 0){
            tmp++;
            n /= prime[i];
        }
        total *= tmp;
    }

    if(n > 10000)return total * 2;
    else return total;
}



void createPrime(){
    isPrime[1] = 1;

    for(int i = 2; i * i <= MAX; i++){
        if(isPrime[i] == 0){
            for(int j = i * i; j <= MAX; j += i){
                isPrime[j] = 1;
            }
            prime[length++] = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    createPrime();

    int L,U,t,ans,max;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&L,&U);
        max = 0;
        for(int i = L; i <= U; i++){
            int x = find(i);
            if(x > max){
                ans = i;
                max = x;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,ans,max);
    }

    return 0;
}
