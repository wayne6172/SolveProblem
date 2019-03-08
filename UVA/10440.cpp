#include <stdio.h>
#include <stdlib.h>

int array[50000];

int main()
{
    int t,can,needTime,size;
    scanf("%d",&t);
    
    while(t--){
    	scanf("%d%d%d",&can,&needTime,&size);
    	for(int i = 0; i < size; i++)
    		scanf("%d",&array[i]);
    	
    	//printf("%d %d\n",array[size-1] + needTime,(size - 1) / can + 1); 此法貪過頭，連老師都抓不出來...
    	
    	
    	int now = 0,nowCan = 0,nowTime = 0, t = 0;
    	
    	if(size % can != 0){
    		int tmp = size % can;
    		for(int i = 0; i < tmp; i++){
    			if(nowTime < array[i])nowTime = array[i];
    		}
    		nowTime += needTime;
    		now = tmp;
    		
    		if(now != size)
    			nowTime += needTime;
    		++t;
    	}
    	
    	while(now < size){
    		++t;
    		nowCan = 0;
    		while(now < size && nowCan < can){
    			if(nowTime < array[now])nowTime = array[now];

    			nowCan++;
    			now++;
    		}
    		nowTime += needTime;
    		
    		if(now != size)
    			nowTime += needTime;

    	}
    	printf("%d %d\n",nowTime,t);
    }
    
    return 0;
}
