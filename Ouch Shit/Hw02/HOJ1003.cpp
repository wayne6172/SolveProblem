#include <cstdio>
#include <cstdlib>

struct item{
	int price,total;
}array[5000];

int cmp(const void *a,const void *b){
	return (*(item *)a).price - (*(item *)b).price;
}

int main()
{
    int N,M;
    while(~scanf("%d%d",&N,&M)){
    	for(int i = 0; i < M; i++)
    		scanf("%d%d",&array[i].price,&array[i].total);
    	
    	qsort(array,M,sizeof(item),cmp);
    	
    	int now = 0, sum = 0;
    	while(now < M){
    		if(N > array[now].total){
    			sum += array[now].price * array[now].total;
    			N -= array[now].total;
    			now++;
    		}
    		else {
    			sum += array[now].price * N;
    			break;
    		}
    	}
    	
    	printf("%d\n",sum);
    }
    
    
    return 0;
}
