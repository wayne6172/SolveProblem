#include <cstdio>
#include <cstdlib>
#include <cmath>

struct range{
	bool can;
	double left,right;
}point[1000];

void setRange(int x,int y,int dis,int target){
	int k = dis * dis - y * y;
	
	if(k < 0)point[target].can = false;
	else {
		point[target].right = x + sqrt(k);
		point[target].left = x - sqrt(k);
		point[target].can = true;
	}
}

int cmp(const void *a,const void *b){
	if((*(range *)a).right > (*(range *)b).right)return 1;
	else if((*(range *)a).right < (*(range *)b).right)return -1;
	else return 0;
}

double find(int target){
	return point[target].right;
}

bool inRange(double nowX,int target){
	if(nowX >= point[target].left && nowX <= point[target].right)return true;
	else return false;
}

int main()
{
    int pairNum,dis,x,y,T = 0;
    while(1){
    	scanf("%d%d",&pairNum,&dis);
    	
    	if(pairNum == 0 && dis == 0)break;
    	
    	bool exit = false;
    	for(int i = 0; i < pairNum; i++){
    		scanf("%d%d",&x,&y);
    		setRange(x,y,dis,i);
    		
    		if(!point[i].can)exit = true;
    	}
    	
    	if(exit){
    		printf("Case %d: -1\n",++T);
    		continue;
    	}
    	
    	qsort(point,pairNum,sizeof(range),cmp);
    	
    	/*for(int i = 0; i < pairNum; i++)
    		printf("%lf %lf\n",point[i].left,point[i].right);*/
    	
    	int now = 0,sum = 0;
    	double nowX;
    	bool isFind = false;
    	while(now < pairNum){
    		if(!isFind){
    			if(point[now].can)
    				nowX = find(now);
    			else break;
    			
    			isFind = true;
    			sum++;
    		}
    		else {
    			if(inRange(nowX,now))now++;
    			else isFind = false;
    		}
    	}
    	
    	printf("Case %d: %d\n",++T,sum);
    }
    
    return 0;
}
