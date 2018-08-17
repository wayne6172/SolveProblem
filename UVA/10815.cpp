#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define MAXCHAR 200
#define MAXWORD 5000

using namespace std;

char dictionary[MAXWORD][MAXCHAR];

int cmp(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}

int main()
{
	char loader[MAXCHAR];
	char c;
	bool isWord = false;
	int len = 0, sum = 0, i;
	
	while(true){
		c = cin.get();
		if(cin.eof())break;
		
		c = tolower(c);
		
		if(isalpha(c) && !isWord){
			isWord = true;
			len = 0;
			loader[len++] = c;
		}
		else if(isalpha(c) && isWord) loader[len++] = c;
		else if(!isalpha(c) && isWord) {
			loader[len++] = '\0';
			
			for(i=0;i<sum;i++){
				if(strcmp(dictionary[i],loader)==0)break;
			}
			
			if(i==sum)strcpy(dictionary[sum++],loader);
			isWord = false;
		}
	}
	
	qsort(dictionary,sum,sizeof(char)*MAXCHAR,cmp);
	
	for(i=0;i<sum;i++)
		cout << dictionary[i] << endl;
	
    return 0;
}