#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,coin[100000],t,sum,now,ans;
    
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i = 0; i < n; i++)
    		scanf("%d",&coin[i]);
    	
    	ans = sum = now = 0;
    	while(now < n){
    		while(now + 1 < n && sum + coin[now] >= coin[now + 1]){
    			now++;
    		}
    		
    		sum += coin[now];
    		now++;
    		ans++;
    		
    		//printf("%d ",sum);
    	}
    	
    	printf("%d\n",ans);
    }
    
    return 0;
}
