#include <cstdio>

int sets[100001];

int find(int t){
	if(sets[t] == t)return t;
	else return sets[t] = find(sets[t]);
}

void Union(int a,int b){
	int set1 = find(a);
	int set2 = find(b);
	
	if(set1 == set2)return;
	
	sets[set2] = set1;
}

int main()
{
    int t,size,p,q,a,b,space = 0;
    char e[5],input[100];
    scanf("%d\n",&t);
    
    while(t--){
    	if(space)printf("\n");
    	else space = 1;
    	a = b = 0;
    	scanf("%d\n",&size);
    	for(int i = 1; i <= size; i++)
    		sets[i] = i;
    	
    	while(1){
    		if(gets(input) == NULL || input[0] == 0)break;
    		sscanf(input,"%s %d %d",e,&p,&q);
    		
    		if(e[0] == 'c'){
    			Union(p,q);
    		}
    		else {
    			if(find(p) == find(q))a++;
    			else b++;
    		}
    	}
    	printf("%d,%d\n",a,b);
    }
    
    return 0;
}
