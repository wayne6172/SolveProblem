#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int e,n;
    priority_queue<int> q;
    
    while(~scanf("%d",&e)){
    	if(e == 1){
    		scanf("%d",&n);
    		q.push(n);
    	}
    	else {
    		if(q.empty())printf("nil\n");
    		else {
    			printf("%d\n",q.top());
    			q.pop();
    		}
    	}
    }
    
    return 0;
}
