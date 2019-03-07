#include <stdio.h>
#include <stdlib.h>

typedef long long int lld;

int mask[50];

lld getAns(int one,int zero){
	int max = one + zero;
	for(int i = 0; i < max; i++)
		mask[i] = 0;
		
	int now = max - 1;
	while(zero * 2 > one + 1){
		mask[now--] = 0;
		zero--;
	}
	
	if(zero && zero * 2 == one + 1){
		mask[now--] = 0;
		mask[now--] = 1;
		one--;
		zero--;
	}
	
	while(one){
		if(zero){
			mask[now--] = 1;
			mask[now--] = 0;
			mask[now--] = 1;
			zero--;
			one-=2;
		}
		else {
			mask[now--] = 1;
			one--;
		}
	}
	
	lld ans = 0;
	for(int i = max - 1; i >= 0; i--)
		ans |= ((lld)mask[i] << i);
	
	return ans;
}

int main()
{
    int t,OneSum,ZeroSum;
    scanf("%d",&t);
    
    while(t--){
    	scanf("%d%d",&OneSum,&ZeroSum);
    	printf("%lld\n",getAns(OneSum,ZeroSum));
    }
    
    return 0;
}

