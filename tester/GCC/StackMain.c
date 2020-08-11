#include <stdio.h>
#include "Stack.h"

int main(int argc, char const *argv[])
{
    int x;
    push(3);
    x = pop();
    printf("x = %d\n",x);

    return 0;
}
