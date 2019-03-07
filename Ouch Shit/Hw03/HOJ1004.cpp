#include <iostream>
#include <algorithm>
using namespace std;

// Given a line of a, b, its output may be empty

int array[10000],len;

bool isPrime(int n){
	if(n == 1)return false;
	bool isprime = true;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			isprime = false;
			break;
		}
	}
	return isprime;
}

int createPal(int input,int b,bool isOdd){
	int n = input;
	int palin = input;
	
	if(isOdd)
		n /= b;
		
	while(n > 0){
		palin = palin * b + (n % b);
		n /= b;
	}
	return palin;
}

void getPalindromes(int n){
	int number;
	
	for(int j = 0; j < 2; j++){
		int i = 1;
		while((number = createPal(i,10,j%2)) < n){
			//cout << number << endl;
			if(isPrime(number)){
				array[len++] = number;
			}
			i++;
		}
	}
}

int main()
{
    getPalindromes(1000000000);
    sort(array,array+len);
    
    int a,b;
   	while(~scanf("%d%d",&a,&b)){
   		for(int i = 0; array[i] <= b && i < len; i++){
   			if(array[i] >= a)
   				cout << array[i] << endl;
   		}
   	}
    
    return 0;
}
