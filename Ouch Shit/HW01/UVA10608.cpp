#include <cstdio>
#include <cstring>

using namespace std;

int set[30000];
int count[30000];

int find(int x){
	if(x == set[x])
		return x;
	return set[x] = find(set[x]);
}

void Union(int x,int y){
	int set1,set2;
	set1 = find(x);
	set2 = find(y);
	
	if(set1 != set2)
		set[set2] = set1;
}

int main()
{
    int t,n,m,a,b;
    scanf("%d",&t);
    
    while(t--){
    	scanf("%d%d",&n,&m);
    	for(int i = 0; i < n; i++)
    		set[i] = i;
    	
    	while(m--){
    		scanf("%d%d",&a,&b);
    		Union(a-1,b-1);
    	}
    	
    	memset(count,0,sizeof(count));
    	for(int i = 0; i < n; i++)
    		count[find(i)]++;
    	
    	int max = 0;
    	for(int i = 0; i < n; i++)
    		if(max < count[i])
    			max = count[i];
    	printf("%d\n",max);
    }
    
    return 0;
}
