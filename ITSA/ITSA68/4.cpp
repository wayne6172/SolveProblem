#include <stdio.h>

typedef unsigned long long ull;


int check(ull n,ull ans){
	ull sum = 0;
	while(n != 0){
		sum += n;
		n /= 10;
	}
	
	if(ans == sum)return 1;
	else return 0;
}

int getDigit(ull n){
	int sum = 0;
	while(n != 0){
		sum++;
		n /= 10;
	}
	return sum;
}

int main(){
	ull n,x,y,maybe,j;
	int digit,i,find;
	
	while(scanf("%llu",&n)!=EOF){
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

		for(j = maybe - 20;j <= maybe + 10;j++){
			if(check(j,n)){
				printf("%llu\n",j);
				find = 1;
				break;
			}
		}
		
		if(find == 0)printf("-1\n");	
	}
	
	return 0;
}
