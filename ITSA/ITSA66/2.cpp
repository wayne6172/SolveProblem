#include <cstdio>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    char input[50];
    int mode,operators;
    double x,b,ans,a;
    while(~scanf("%s",input)){
        mode = -1;

        if(input[0] == 'x')mode = 0;
        else a = atof(input);

        scanf("%s",input);
        if(input[0] == '+')operators = 0;       
        else if(input[0] == '-')operators = 1;
        else if(input[0] == '*')operators = 2;
        else operators = 3;

        scanf("%s",input);

        if(input[0] == 'x')mode = 1;
        else {
            b = atof(input);
            if(mode == -1)mode = 2;
        }

        scanf("%s",input);      // = 

        if(mode != 2)scanf("%lf",&ans);
        else scanf("%s",input);

        if(mode == 0){      // X ? b = ans
            if(operators == 0){     // X + b = ans
                x = ans - b;
            }
            else if(operators == 1){    // X - b = ans
                x = ans + b;
            }
            else if(operators == 2){    // X * b = ans
                x = ans / b;
            }
            else {                  // x / b = ans
                x = ans * b;
            }
        }
        else if(mode == 1){      // a ? x = ans
            if(operators == 0){     // a + X = ans
                x = ans - a;
            }
            else if(operators == 1){    // a - X = ans
                x = a - ans;
            }
            else if(operators == 2){    // a * X = ans
                x = ans / a;
            }
            else {                  // a / X = ans
                x = a / ans;
            }
        }
        else {
            if(operators == 0){     // a + b = x
                x = a + b;
            }
            else if(operators == 1){    // a - b = x
                x = a - b;
            }
            else if(operators == 2){    // a * b = x
                x = a * b;
            }
            else {                  // a / b = x
                x = a / b;
            }
        }
        printf("%.1lf\n",x);
    }

    return 0;
}
