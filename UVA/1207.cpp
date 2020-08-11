#include <cstdio>
#include <cstring>
#define MIN(a,b) ((a > b) ? b : a)



int main(){
    char A[10000],B[10000];
    int A_len, B_len;

    while(~scanf("%d %s %d %s",&A_len,A,&B_len,B)){
        int dp[A_len + 1][B_len + 1];
        memset(dp,0,sizeof(dp));

        for(int i = 0; i <= A_len; i++)
            dp[i][0] = i;
        for(int i = 0; i <= B_len; i++)
            dp[0][i] = i;

        for(int i = 1; i <= A_len; i++){
            for(int j = 1; j <= B_len; j++){
                if(A[i - 1] != B[j - 1])
                    dp[i][j] = MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                else 
                    dp[i][j] = MIN(dp[i - 1][j - 1], MIN(dp[i][j - 1], dp[i - 1][j]) + 1);
            }
        }

        printf("%d\n",dp[A_len][B_len]);
    }

    return 0;
}
