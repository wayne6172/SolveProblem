#include <cstdio>

int main(int argc, char const *argv[])
{
    double x,xi,y,yi;
    scanf("%lf %lf %lf %lf",&x,&xi,&y,&yi);

    printf("(%.2lf)+(%.2lf)i\n",(x + y),(xi + yi));
    printf("(%.2lf)+(%.2lf)i\n",(x - y),(xi - yi));
    printf("(%.2lf)+(%.2lf)i\n",(x * y - xi * yi),(xi * y + yi * x));

    return 0;
}
