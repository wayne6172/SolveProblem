#include <stdio.h>
#include <math.h>

int table[32768][15];

int main(){
	int i,j,k,x,s,n,t;
	
	x = 1;
	for(i = 14;i >= 0; i--,x *= 2){
		for(j = 0;j < 32768; j += (x * 4)){
			for(k = 0;k < x;k++)table[j + k][i] = 0;
			for(k = 0;k < x;k++)table[j + k + x][i] = 1;
			if(i == 0)break;
			for(k = 0;k < x;k++)table[j + k + x * 2][i] = 1;
			for(k = 0;k < x;k++)table[j + k + x * 3][i] = 0;
		}
	}
	
	while(scanf("%d",&n)!=EOF){
		t = pow(2,n);
		
		for(i = 0; i < t;i++){
			for(j = 15 - n;j < 15;j++)
				printf("%d",table[i][j]);
			printf("\n");
		}
	}
	
	
	
	return 0;
}
