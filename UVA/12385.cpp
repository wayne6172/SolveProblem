#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (a > b ? a : b)

int last[100001];
int front[100000];

int solve(int size){
	int dp[100000] = {0};
	
	for(int i = 1; i < size; i++){
		if(front[i] != -1){
			dp[i] = max(dp[i-1],dp[front[i]] + 1);
		}
		else
			dp[i] = dp[i-1];
	}
	
	
	return dp[size - 1];
}

int main()
{
    int t,n,num;
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	
    	memset(last,-1,sizeof(last));
    	for(int i = 0; i < n; i++){
    		scanf("%d",&num);
    		if(last[num]!= -1){
    			front[i] = last[num];
    		}
    		else {
    			front[i] = -1;
    		}
    		last[num] = i;
    	}
    	
    	printf("%d\n",solve(n));
    }
    
    
    return 0;
}
