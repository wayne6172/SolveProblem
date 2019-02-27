#include <cstdio>

int set[10000];
int coin[10000];
int sum[10000];

void resetSet(int n){
	for(int i = 0; i < n; i++){
		set[i] = i;
		sum[i] = 0;
	}
}

int find(int target){
	if(set[target] == target)return target;
	else return set[target] = find(set[target]);
}

void Union(int a,int b){
	int set1 = find(a);
	int set2 = find(b);
	
	if(set1 == set2)return;
	
	set[set2] = set1;
}

int main()
{
    int T,n,pair,a,b;
    scanf("%d",&T);
    
    while(T--){
    	scanf("%d%d",&n,&pair);
    	resetSet(n);
    	
    	for(int i = 0; i < n; i++)
    		scanf("%d",&coin[i]);
    	
    	for(int i = 0; i < pair; i++){
    		scanf("%d%d",&a,&b);
    		
    		Union(a,b);
    	}
    	
    	for(int i = 0; i < n; i++){
    		sum[find(i)] += coin[i];
    	}
    	
    	bool possible = true;
    	for(int i = 0; i < n; i++){
    		if(sum[i]){
    			possible = false;
    			break;
    		}
    	}
    	
    	possible ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
