#include <stdio.h>

typedef long long lld;


int check(lld n,lld ans){
	lld sum = 0;
	while(n != 0){
		sum += n;
		n /= 10;
	}
	
	if(ans == sum)return 1;
	else return 0;
}

int getDigit(lld n){
	int sum = 0;
	while(n != 0){
		sum++;
		n /= 10;
	}
	return sum;
}

int main(){
	lld n,x,y,maybe,j;
	int digit,i,find;
	
	while(scanf("%lld",&n)!=EOF){
		digit = getDigit(n);
		find = 0;
		
		y = 1;
		for(i = 1;i < digit;i++){
			y *= 10;
		}
		
		x = 1;
		for(i = 1;i < digit;i++){
			x *= 10;
			x++;
		}
		
		maybe = n * ((double)y / (double)x);
		//printf("%lld\n",maybe);

		for(j = maybe - 2000;j <= maybe + 1000;j++){
			if(check(j,n)){
				printf("%lld\n",j);
				find = 1;
				break;
			}
		}
		
		if(find == 0)printf("-1\n");	
	}
	
	return 0;
}
