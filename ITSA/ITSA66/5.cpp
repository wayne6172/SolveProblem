#include <cstdio>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    char A[100],B[100];
    int max,sum,ans;

    while(~scanf("%s%s",A,B)){
        max = 0;
        for(int i = 0;A[i];i++){
            for(int j = 0;B[j];j++){
                if(A[i]==B[j]){
                    int a = i, b = j, sum = 0;
                    while(A[a] == B[b] && A[a] && B[b]){
                        a++,b++;
                        sum++;
                    }
                    if(sum > max){
                        max = sum;
                        ans = i;
                    }
                    j = b;
                }
            }
        }
        if(max == 0){
            printf("No common sequence!\n");
            continue;
        }

        for(int i = 0;i < max;i++)
            printf("%c",A[ans + i]);
        printf("\n");
    }

    return 0;
}

