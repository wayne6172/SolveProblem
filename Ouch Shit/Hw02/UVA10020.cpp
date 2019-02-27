#include <stdio.h>
#include <stdlib.h>

struct point{
	int left,right;
}array[100000],ans[100000];

bool canUse(int left,int right,int M){
	return !(right <= 0 || left >= M);
}

int cmp(const void *a,const void *b){
	return (*(point *)a).left - (*(point *)b).left;
}

bool inRange(int target, int nowX){
	return (array[target].left <= nowX && array[target].right >= nowX) || array[target].right <= nowX;
}

int main(int argc, char *argv[])
{
    int T,M,i,left,right,ansNum,space = 0;
    scanf("%d",&T);
    while(T--){
    	if(space)printf("\n");
    	else space = 1;
    
    	scanf("%d",&M);
    	
    	ansNum = i = 0;
    	while(1){
    		scanf("%d%d",&left,&right);
    		if(left == 0 && right == 0)break;
    		
    		
    		if(canUse(left,right,M)){
    			array[i].left = left;
    			array[i].right = right;
    			//printf("%d %d\n",left,right);
    			i++;
    		}
    	}
    	qsort(array,i,sizeof(point),cmp);
    	
    	int nowX = 0, nowSeg = 0,max,next = 0;
    	while(nowX < M){
    		if(nowSeg == i)break;
    		max = 0;
    		while(nowSeg < i && inRange(nowSeg,nowX)){
    			if(max < array[nowSeg].right){
    				next = nowSeg;
    				max = array[nowSeg].right;
    			}
    			nowSeg++;
    		}
    		if(max == 0)break;
    		
    		ans[ansNum++] = array[next];
    		nowX = array[next].right;
    	}
    	if(nowX < M)ansNum = 0;
    	
    	printf("%d\n",ansNum);
    	for(int j = 0; j < ansNum; j++)
    		printf("%d %d\n",ans[j].left,ans[j].right);
    }
    
    return 0;
}
