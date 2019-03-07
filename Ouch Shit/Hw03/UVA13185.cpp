#include <stdio.h>
#include <stdlib.h>

int getAns(int n){
	int i;
	
	int ans = 0;
	for(i = 2; i * i < n; i++){
		if(n % i == 0)
			ans += i + (n / i);
	}
	
	if(i * i == n)ans += i;
	return ans + 1;
}

int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	k = getAns(n);
    	
    	if(k == n)printf("perfect\n");
    	else if(k < n)printf("deficient\n");
    	else printf("abundant\n");
    }
    
    return 0;
}
