#include <stdio.h>
#include <ctype.h>

int main(){
	char input[200];
	int n,isWord,i;
	
	while(gets(input)){
		
		if(!isalpha(input[i])){
			isWord = 0;
			n = 0;	
		}
		else {
			isWord = 1;
			n = 1;	
		}
		
		int sum[52]={0};
		
		for(i=0;input[i];i++){
			
			if(isWord == 0 && isalpha(input[i])){
				n++;
				isWord = 1;
			}
			else if(!isalpha(input[i]) && isWord == 1)isWord = 0;
			
			
			if(isalpha(input[i])){
				if(input[i] >= 'a' && input[i] <= 'z'){
					sum[input[i]-'a']++;
				}
				else{
					sum[input[i]-'A'+26]++;
				}
			}
		}
		
		printf("%d\n",n);
		
		for(i = 0;i < 26;i++){
			if(sum[i+26] > 0){
				printf("%c : %d\n",'A' + i,sum[i+26]);
			}
			if(sum[i] > 0){
				printf("%c : %d\n",'a' + i,sum[i]);
			}
		}
	}
	
	return 0;
}
