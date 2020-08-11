#include <stdio.h>

int win_sum, total;

void check(int a,int b,int c,int player){
    if(a == 0 && b == 0 && c == 0){
        if(player == 1)
            win_sum++;
        
        total++;
    }

    int i;
    for(i = 1; i <= 2 && a - i >= 0; i++)
        check(a - i, b, c, (player + 1) % 2);
    for(i = 1; i <= 2 && b - i >= 0; i++)
        check(a, b - i, c, (player + 1) % 2);
    for(i = 1; i <= 2 && c - i >= 0; i++)
        check(a, b, c - i, (player + 1) % 2);
    
}

void printState(int a, int b, int c){
    int i;

    printf("\n\n");
    printf("#1: ");
    for(i = 0; i < a; i++)printf("*");
    printf("\n");

    printf("#2: ");
    for(i = 0; i < b; i++)printf("*");
    printf("\n");
    
    printf("#3: ");
    for(i = 0; i < c; i++)printf("*");
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    int a, b, c, player = 0, choose, choose_num, i;

    scanf("%d%d%d", &a, &b, &c);

    while(a >= 0 || b >= 0 || c >= 0){
        printState(a, b, c);

        if(player == 0){
            scanf("%d%d", &choose, &choose_num);

            if(choose == 1)
                a -= choose_num;
            if(choose == 2)
                b -= choose_num;
            if(choose == 3)
                c -= choose_num;
        }
        else {
            int want = -1, want_num = -1;
            double max = -1, acc;

            for(i = 1; i <= 2 && a - i >= 0; i++){
                win_sum = total = 0;
                check(a - i, b, c, player);
                acc = (double)win_sum / total;

                if(acc > max){
                    want = 1;
                    want_num = i;
                    max = acc;
                }
            }

            for(i = 1; i <= 2 && b - i >= 0; i++){
                win_sum = total = 0;
                check(a, b - i, c, player);
                acc = (double)win_sum / total;

                if(acc > max){
                    want = 2;
                    want_num = i;
                    max = acc;
                }
            }

            for(i = 1; i <= 2 && c - i >= 0; i++){
                win_sum = total = 0;
                check(a, b, c - i, player);
                acc = (double)win_sum / total;

                if(acc > max){
                    want = 3;
                    want_num = i;
                    max = acc;
                }
            }

            printf("I want remove #%d   %d\n", want, want_num);

            if(want == 1)
                a -= want_num;
            if(want == 2)
                b -= want_num;
            if(want == 3)
                c -= want_num;
        }


        if(a == 0 && b == 0 && c == 0)break;


        player = (player + 1) % 2;
    }

    printf("player %d win.\n", player);

    return 0;
}