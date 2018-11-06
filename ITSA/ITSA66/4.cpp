#include <cstdio>
#include <cstdlib>

char a[11][10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"};
char b[11][10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"};
char c[11][10] = {"","I","II","III","IV","V","VI","VII","VIII","IX","X"};

int main(int argc, char const *argv[])
{
    int n,x;
    scanf("%d",&n);

    while(n--){
        scanf("%d",&x);
        printf("%s%s%s\n",a[x/100],b[x/10%10],c[x%10]);
    }

    return 0;
}
