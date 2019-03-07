#include <iostream>

using namespace std;

int digit[19];
int appear[10];

void give(int d,int size){
	int find = -1;
	
	for(int i = d; i < size; i++){
		for(int j = digit[i] - 1; j >= 0; j--){
			if(appear[j] < 2){
				find = i;
				
				if(i != d)
					appear[digit[i]]--;
				digit[i] = j;
				appear[digit[i]]++;
				break;
			}
		}
		
		if(find >= 0)break;
		
		if(d != i)
			appear[digit[i]]--;
	}
	
	
	//printf("%d\n",appear[9]);
	
	int get = 9;
	for(int i = find - 1; i >= 0; i--){
		while(appear[get] >= 2)
			get--;
		
		digit[i] = get;
		appear[get]++;
	}
}

int main()
{
    long long int input;
    int now;
    while(~scanf("%lld",&input)){
    	now = 0;
    	while(input != 0){
    		digit[now++] = input % 10;
    		input /= 10;
    	}
    	
    	for(int i = 0; i < 10; i++)
    		appear[i] = 0;
    	
    	for(int i = now - 1; i >= 0; i--){
    		if(appear[digit[i]] >= 2){
    			give(i,now);
    			break;
    		}
    		else appear[digit[i]]++;
    	}
    	
    	if(digit[now - 1] == 0)now--;
    	for(int i = now - 1; i >= 0; i--)
    		printf("%d",digit[i]);
    	printf("\n");
    }
    
    return 0;
}
