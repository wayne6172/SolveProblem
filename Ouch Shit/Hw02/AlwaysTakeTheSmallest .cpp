#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll e,n;
    priority_queue< ll,vector<ll>,greater<ll> > q;
    
    while(~scanf("%lld",&e)){
    	if(e == 1){
    		scanf("%lld",&n);
    		q.push(n);
    	}
    	else {
    		if(q.empty())printf("nil\n");
    		else {
    			printf("%lld\n",q.top());
    			q.pop();
    		}
    	}
    }
    
    return 0;
}
