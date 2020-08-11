#include <cstdio>
#include <cstdlib>
#include <memory.h>

struct poly{
    int maxDegree;
    int coef[100];
};

poly div(poly a, poly b){
    poly result;
    memset(result, 0, sizeof(result));


    
}

int main(int argc, char const *argv[])
{
    poly a, b, c;

    int expoBuffer[100],coefBuffer, len = 0;
    int t;
    char p;

    scanf("%d", &t);
    while(t--){

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        len = 0;
        while(1){
            scanf("%d%c", &expoBuffer[len++], &p);
            if(p == '\n')break;
        }

        for(int i = 0; i < len; i++){
            scanf("%d", &coefBuffer);
            if(i == 0)
                a.maxDegree = expoBuffer[i];
            a.coef[expoBuffer[i]] = coefBuffer;
        }
        
        len = 0;
        while(1){
            scanf("%d%c", &expoBuffer[len++], &p);
            if(p == '\n')break;
        }

        for(int i = 0; i < len; i++){
            scanf("%d", &coefBuffer);
            if(i == 0)
                b.maxDegree = expoBuffer[i];
            b.coef[expoBuffer[i]] = coefBuffer;
        }

        c = div(a, b);
    }

    

    return 0;
}
/*

  2 + 1 | 5 + 0 + 0 + 3

*/