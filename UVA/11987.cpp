#include <iostream>

using namespace std;

int code[100001];
int set[200001];
int total[200001];
int sum[200001];

int find(int x){
	if(x == set[x])return x;
	return set[x] = find(set[x]);
}


void Union(int x,int y){
	int set1,set2;
	set1 = find(code[x]);
	set2 = find(code[y]);
	
	if(set1 !=set2){
		set[set2] = set1;
		total[set1] += total[set2];
		sum[set1] += sum[set2];
	}
}

int main()
{
    int n,m,e,p,q,cash;
    while(~scanf("%d%d",&n,&m)){
    	for(int i = 1; i <= n; i++){
    		code[i] = set[i] = total[i] = i;
    		sum[i] = 1;
    	}
    	cash = n + 1;
    	while(m--){
    		scanf("%d",&e);
    		
    		if(e == 1){
    			scanf("%d%d",&p,&q);
    			Union(p,q);
    		}
    		else if(e == 2){
    			scanf("%d%d",&p,&q);
    			
    			int set1 = find(code[p]);
    			sum[set1] -= 1;
    			total[set1] -= p;
    			
    			set[cash] = cash;
    			sum[cash] = 1;
    			total[cash] = p;
    			code[p] = cash;
    			cash++;
    			
    			Union(p,q);
    		}
    		else {
    			scanf("%d",&p);
    			int set1 = find(code[p]);
    			printf("%d %d\n",sum[set1],total[set1]);
    		}
    	}
    	
    }
    
    return 0;
}
