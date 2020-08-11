#include <cstdio>

int main(int argc, char const *argv[])
{
    int test, ball, B = -1, C = -1, i, flag;
    scanf("%d", &test);

    while(test--){
        flag = 1;
        for(i = 0; i < 10; i++){
            scanf("%d", &ball);

            if(B < ball)
                B = ball;
            else if(C < ball)
                C = ball;
            else flag = 0;
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
