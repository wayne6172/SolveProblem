#include <cstdio>
#include <cstring>

using namespace std;

bool map[26][26];
bool isWake[26];
bool nextWake[26];

bool checkWake(int n){
	int sum = 0;
	for(int i = 0; i < 26; i++)
		if(isWake[i])sum++;
	
	return n == sum;
}

bool updateWake(){
	memset(nextWake,0,sizeof(nextWake));
	
	bool haveWake = false;
	int sum;
	for(int i = 0; i < 26; i++){
		sum = 0;
		if(!isWake[i]){
			for(int j = 0; j < 26; j++){
				if(map[i][j] && isWake[j])sum++;
			}
			
			if(sum >= 3){
				nextWake[i] = true;
				haveWake = true;
			}
		}
	}
	return haveWake;
}

int main()
{
    int n,cmd,year;
    char input[10];
    
    while(~scanf("%d%d",&n,&cmd)){
    	memset(map,0,sizeof(map));
    	memset(isWake,0,sizeof(isWake));
    	
    	year = 0;
    	
    	scanf("%s",input);
    	isWake[input[0]-'A'] = true;
    	isWake[input[1]-'A'] = true;
    	isWake[input[2]-'A'] = true;
    	
    	while(cmd--){
    		scanf("%s",input);
    		map[input[0]-'A'][input[1]-'A'] = true;
    		map[input[1]-'A'][input[0]-'A'] = true;
    	}
    	
    	while(!checkWake(n)){
    		if(!updateWake())break;
    		
    		year++;
    		for(int i = 0; i < 26; i++)
    			isWake[i] |= nextWake[i];
    	}
    	
    	if(checkWake(n))printf("WAKE UP IN, %d, YEARS\n",year);
    	else printf("THIS BRAIN NEVER WAKES UP\n");
    }
    
    return 0;
}
