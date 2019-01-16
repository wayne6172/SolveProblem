#include <cstdio>

typedef unsigned long long ULL;

ULL fib[50];

void createFib(){
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i < 50; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
}

void find(ULL i,int left,int right,int N){

	if(N == 0){
		printf("0");
		return;
	}
	else if(N == 1){
		printf("1");
		return;
	}

	ULL mid = i + fib[N-2];
	if(right < mid)find(i,left,right,N - 2);
	else if(left >= mid)find(mid,left,right,N - 1);
	else {
		find(i,left,mid - 1,N - 2);
		find(mid,mid,right,N - 1);
	}
}

int main()
{
	createFib();
	
	int t,n,a,b;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d%d",&n,&a,&b);
		if(n>50) n = n % 2 ? 49 : 48;
		
		find(0,a,b,n);
		
		printf("\n");
	}
    
    return 0;
}
