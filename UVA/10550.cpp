#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start,a,b,c;
    while(scanf("%d%d%d%d",&start,&a,&b,&c)&&(start||a||b||c)){
    	int ans = 80 + (start+40-a)%40 + 40 + (b+40-a)%40 + (b+40-c)%40;
    	printf("%d\n",ans*9);  
    }
    
    return 0;
}
