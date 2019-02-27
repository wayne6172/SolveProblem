#include <cstdio>

int total[10000];

int main(){
	int N,n,**list;
	scanf("%d",&N);
	list = new int *[N];
	for(int i = 0; i < N; i++){
		scanf("%d",&total[i]);
		list[i] = new int[total[i]];
		for(int j = 0; j < total[i]; j++)
			scanf("%d",&list[i][j]);
	}
	
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a <= N){
			if(b <= total[a - 1]){
				printf("%d\n",list[a - 1][b - 1]);
			}
			else printf("nil\n");
		}
		else printf("nil\n");
	}
	
	
	return 0;
}