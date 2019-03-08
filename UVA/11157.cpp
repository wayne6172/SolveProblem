#include <stdio.h>
#include <stdlib.h>

struct rock{
	char e;
	int pos;
}rocks[105];

int main()
{
    int t,dis,size,T = 0;
    char input[1000];
    
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&size,&dis);
    	
    	rocks[0].e = 'B';
    	rocks[0].pos = 0;
    	for(int i = 1; i <= size; i++){
    		scanf("%s",input);
    		rocks[i].e = input[0];
    		rocks[i].pos = atoi(&input[2]);
    	}
    	size++;
    	rocks[size].e = 'B';
    	rocks[size].pos = dis;
    	size++;
    	
    	int frontB = 0, nowB = 1, max = 0,haveS;
    	
    	while(1){
	    	while(nowB < size && rocks[nowB].e != 'B')nowB++;
	    	if(nowB == size)break;
	    	
	    	int frontS = frontB;
	    	for(int i = frontB + 1; i <= nowB; i+= 2){
	    		if(rocks[i].pos - rocks[frontS].pos > max)
	    			max = rocks[i].pos - rocks[frontS].pos;
	    		frontS = i;
	    	}
	    	
	    	frontS = frontB;
	    	for(int i = frontB + 2; i <= nowB; i+= 2){
	    		if(rocks[i].pos - rocks[frontS].pos > max)
	    			max = rocks[i].pos - rocks[frontS].pos;
	    		frontS = i;
	    	}
	    	//printf("%d %d\n",max,nowB,size);
	    	frontB = nowB;
	    	nowB++;
	    	
	    	//return 0;
    	}
    	printf("Case %d: %d\n",++T,max);
    }
    
    return 0;
}
