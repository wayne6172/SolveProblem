#include <stdio.h>

int bitA[32];
int bitB[32];

void tran(unsigned a,unsigned b){
	int i = 0;
	for(i = 0;i < 32; i++){
		bitA[i] = a % 2;
		a /= 2;
	}
	
	i = 0;
	for(i = 0;i < 32; i++){
		bitB[i] = b % 2;
		b /= 2;
	}
	
}

unsigned getN(int m){
	unsigned k = 1,i,sum = 0;
	for(i=0;i<32;i++){
		if(bitA[i]==1)sum+=k;
		k *= 2;
	}
	return sum;
}

int main(){
	int m,t,i,j,x,first = 1;
	unsigned s,d,n;
	
	while(scanf("%d%u%u",&m,&s,&d)!=EOF){
		tran(s,d);
		n = s;
		t = m;
		
		for(i=m-1;i>=0;i--){
			first = 1;
			n = getN(m);
			printf("%u ",n);
			
			for(j=0;j<m;j++){
				x = ((i - j) + m) % m;
				
				if(first && bitA[x] == bitB[x]){
					if(bitB[x] == 1)bitA[x] = 0;
					else bitA[x] = 1;
				}
				else if(bitA[x] != bitB[x]){
					bitA[x] = bitB[x];
				}
				else if(bitA[x] == bitB[x]){
					continue;
				}
				n = getN(m);
				if(n == d)break;
				
				printf("%u ",n);
				
				first = 0;
			}
			printf("%u\n",d);
			tran(s,d);
			
		}
		
	}
	
	
	return 0;
}
