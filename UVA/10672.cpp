#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int front[10001];

struct pair{
	int layer,n;
}layer[10001];

int findLayer(int t){
	if(front[t] == 0)return 0;
	else return findLayer(front[t]) + 1;
}

int cmp(const void *a,const void *b){
	if((*(pair *)a).layer == (*(pair *)b).layer){
		return (*(pair *)a).n - (*(pair *)b).n;
	}
	else return (*(pair *)b).layer - (*(pair *)a).layer;
}

int main()
{
    int size,target,have[10001],childSum,child;
    
    while(~scanf("%d",&size)){
    	if(size==0)break;
    	
    	memset(front,0,sizeof(front));
    	
    	for(int i = 0; i < size; i++){
    		scanf("%d",&target);
    		scanf("%d",&have[target]);
    		
    		scanf("%d",&childSum);
    		for(int j = 0; j < childSum; j++){
    			scanf("%d",&child);
    			front[child] = target;
    		}
    		layer[target].n = target;
    	}
    	
    	for(int i = 1; i <= size; i++){
    		layer[i].layer = findLayer(layer[i].n);
    	}
    	
    	qsort(&layer[1],size,sizeof(pair),cmp);
    	
    	int ans = 0,mask[10001] = {0};
    	for(int i = 1; i <= size; i++){
    		if(have[layer[i].n] + mask[layer[i].n] < 1){
    			ans += 1 - (have[layer[i].n] + mask[layer[i].n]);
    			mask[front[layer[i].n]] += have[layer[i].n] + mask[layer[i].n] - 1;
    		}
    		else if(have[layer[i].n] + mask[layer[i].n] > 1){
    			ans += have[layer[i].n] + mask[layer[i].n] - 1;
    			mask[front[layer[i].n]] +=  have[layer[i].n] + mask[layer[i].n] - 1;
    		}
    		//printf(" %d\n",ans);
    	}
    	printf("%d\n",ans);
    }
    
    return 0;
}
