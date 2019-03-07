#include <stdio.h>
#include <stdlib.h>

int array[100000];
int can[100000];
int cant[100000];

int abs(int k){
	return k >= 0 ? k : -k;
}

int main(int argc, char *argv[])
{
    int t,i,canLen,cantLen;
    while(true){
	    scanf("%d",&t);
	    
	    if(t == 0)break;
	    
	    canLen = cantLen = 0;
	    for(int i = 0; i < t; i++){
	    	scanf("%d",&array[i]);
	    	if(array[i] < 0)
	    		cant[cantLen++] = i;
	    	if(array[i] > 0)
	    		can[canLen++] = i;
	    }
	    
	    int nowCant = 0,nowCan = 0;
	    long long int ans = 0;
	    while(nowCant < cantLen){
			if(-array[cant[nowCant]] > array[can[nowCan]]){ 		//供不應求
				ans += abs(cant[nowCant] - can[nowCan]) * array[can[nowCan]];
				
				array[cant[nowCant]] += array[can[nowCan]];
				array[can[nowCan]] = 0;
				
				nowCan++;
			}	
			else if(-array[cant[nowCant]] < array[can[nowCan]]){		//供過於求
				ans += abs(cant[nowCant] - can[nowCan]) * -array[cant[nowCant]];
				
				array[can[nowCan]] += array[cant[nowCant]];
				array[cant[nowCant]] = 0;
				
				nowCant++;
			}
			else {
				ans += abs(cant[nowCant] - can[nowCan]) * array[can[nowCan]];
				
				array[cant[nowCant]] = 0;
				array[can[nowCan]] = 0;
				
				nowCant++;
				nowCan++;
			}
	    		
	    }
	    printf("%lld\n",ans);
    }
    
    return 0;
}
