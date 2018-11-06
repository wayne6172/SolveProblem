#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    char input[1000],*p;
    int array[15],length,sum,ans,find;

    while(gets(input)){
        length = find = 0;
        p = strtok(input," ");
        while(p != NULL){
            array[length++] = atoi(p);
            p = strtok(NULL," ");
        }

        for(int i = 0; i < length;i++){
            sum = 1;
            for(int j = i + 1; j < length; j++){
                if(array[i] == array[j])sum++;
            }
            if(sum > length / 2){
                find = 1;
                ans = array[i];
            }
        }

        if(find == 1)printf("%d\n",ans);
        else printf("NO\n");
    }

    return 0;
}
