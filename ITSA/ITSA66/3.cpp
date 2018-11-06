#include <cstdio>
#include <cstdlib>
#include <cstring>

bool check(char c){
    if(c == ';' || c == ',' || c == ':')return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    int n;
    char input[300000],*p;
    scanf("%d\n",&n);
    while(n--){
        gets(input);
        printf("Tokens found:\n");
        for(int i = 0;input[i];i++){
            if(check(input[i]))printf("\n");
            else printf("%c",input[i]);
        }
        printf("\n");
    }

    return 0;
}
