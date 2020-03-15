#include <stdio.h>

// infix  -> 5 * 22 + 13 * 4 * 6 + 12 + 5 = 439 
// prefix -> + + + * 5 22 * * 13 4 6 12 5, length is 28

int stringToInteger(char input[], int left, int right){
    int sum = 0, i;
    for(i = left; i <= right; i++){
        sum *= 10;
        sum += (input[i] - '0');
    }

    return sum;
}

int getMid(char input[], int left, int right){
    int now = left, flag = 0;
    int operatorSum = 0, operandSum = 0;

    while(now <= right){
        if(input[now] >= '0' && input[now] <= '9'){
            if(flag == 0){
                flag = 1;
                operandSum++;
            }
        }
        else if(input[now] != ' '){          // + or *
            operatorSum++;
        }
        else flag = 0;              // is space
        
        if(operatorSum == operandSum && flag == 0)break;

        now++;
    }

    return now;
}

int solvePrefix(char input[], int left, int right){
    int mid = getMid(input, left, right), operand1, operand2;
    
    if(mid > right)
        return stringToInteger(input, left, right);
    else {
        operand1 = solvePrefix(input, left + 2, mid - 1);
        operand2 = solvePrefix(input, mid + 1, right);

        if(input[left] == '+')
            return operand1 + operand2;
        if(input[left] == '*')
            return operand1 * operand2;
    }
}

int main(int argc, char const *argv[])
{
    int size, i;

    scanf("%d", &size);
    getchar();

    char input[size];

    for(i = 0; i < size; i++)
        scanf("%c", &input[i]);
    getchar();

    printf("%d\n", solvePrefix(input, 0, size - 1));

    return 0;
}
