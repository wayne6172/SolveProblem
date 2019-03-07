#include <stdio.h>
#include <stdlib.h>

typedef long long int lld;

lld count[32][32];
lld mask[32];

lld getDigit(int t){
	if(t < 0)return 0;

	lld ans = 0;
	int count = 0;
	
	int i;
	for(i = 30; i >= 0; i--){
		if((t & (1 << i))){
			ans += mask[i];
			ans += count * (1 << i);
			
			count++;
		}
	}
	return ans;
}

void initMask(){
	mask[0] = 1;
	lld sum;
	for(int i = 1; i < 32; i++){
		sum = 0;
		for(int j = 0; j < i; j++){
			sum += (1 + j) * count[i][j];
		}
		sum += mask[i-1];
		mask[i] = sum;
	}
}

void initCount(){
	for(int i = 3; i <= 31; i++){
		count[i][0] = 1;
		
		int j;
		for(j = 1; j + 1 < i; j++){
			count[i][j] = count[i-1][j-1] + count[i-1][j];
		}
		count[i][j] = 1;
	}
}

int main()
{
	int a,b,t = 0;
    count[1][0] = count[2][0] = count[2][1] = 1;
    initCount();
    initMask();
    
    while(~scanf("%d%d",&a,&b)){
    	if(!a && !b)break;
    	printf("Case %d: %lld\n",++t,getDigit(b) - getDigit(a-1));
    }
    
    return 0;
}

