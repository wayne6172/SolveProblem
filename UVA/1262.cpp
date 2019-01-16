#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[12][6];
char dic[5][7];

int cmp(const void *a,const void *b){
	return *(char *)a - *(char *)b;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	n--;
    	for(int i=0;i<12;i++)
    		scanf("%s",input[i]);
    	
    	memset(dic,0,sizeof(dic));
    	for(int k=0;k<5;k++){
    		for(int i=0;i<6;i++){
    			for(int j=6;j<12;j++){
    				int len = strlen(dic[k]),find = 0;
    				if(input[i][k] == input[j][k]){	
	    				for(int l=0;l<len;l++){
	    					if(dic[k][l]==input[i][k])find = 1;
	    				}
	    				if(find == 0)
	    					dic[k][len] = input[i][k];
    				}
    			}
    		}
    		qsort(dic[k],strlen(dic[k]),sizeof(char),cmp);
    	}
    	
    	int total = 1;
    	for(int i=0;i<5;i++){
    		total *= strlen(dic[i]);
    	}
    	
    	if(total <= n)printf("NO\n");
    	else {
    		for(int i=0;i<5;i++){
    			int k = total / strlen(dic[i]);
    			
    			printf("%c",dic[i][n/k]);
    			n %= k;
    			total /= strlen(dic[i]);
    		}
    		printf("\n");
    	}
    }

    return 0;
}
