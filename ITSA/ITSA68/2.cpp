#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choose[100];
int array[100];

int total,W;

int find(int k,int N,int sum,int Y){
	int i,e;
	
	if(total > W){
		return -1;
	}
	
	if(sum == Y){
		if(total == W)return 1;
		else return -1;
	}
	
	for(i = k;i < N;i++){
		total += array[i];
		choose[i] = 1;
		e = find(i+1,N,sum+1,Y);
		if(e == 1)return 1;
		
		total -= array[i];
		choose[i] = 0;
	}
}

int main(){
	char input[5000],*p;
	int Y,N,i,first;
	
	while(gets(input)){
		total = 0;
		p = strtok(input,",");
		W = atoi(p);
		
		p = strtok(NULL,",");
		Y = atoi(p);
		
		p = strtok(NULL,",");
		N = atoi(p);
		
		for(i = 0;i < N;i++){
			p = strtok(NULL,",");
			array[i] = atoi(p);
		}
		
		find(0,N,0,Y);
		first = 1;
		for(i = 0;i < N;i++){
			
			if(choose[i] == 1){
				if(first != 1)printf(",");
				first = 0;
				printf("k%d",i);
			}
		}
		printf("\n");
		
	}
	
	return 0;
}
