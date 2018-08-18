#include <iostream>
#define MAX 5000

using namespace std;

int item[MAX];

void addArray(int item[],int n,int &size){
    int i,j;
    if(size == MAX)return;

    for(i = 0;i < size;i++){
        if(n < item[i])break;
    }

    for(j = size - 1; j >= i ;j--){
        item[j + 1] = item[j];
    }

    item[i] = n;
    size++;
}

void removeArray(int item[],int n,int &size){
    int i,j;
    for(i = 0; i < size;i++){
        if(n == item[i])break;
    }

    if(i == size)return;
    else {
        for(j = i; j < size - 1;j++){
            item[j] = item[j + 1];
        }
        size--;
    }
}

void printArray(int item[],int size){
    for(int i=0;i<size;i++)
        cout << item[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n,size = 0,choose;
    while(true){
        cin >> choose >> n;
        if(cin.eof())break;
        
        if(choose == 1)
            addArray(item,n,size);
        else if(choose == 2)
            removeArray(item,n,size);
        printArray(item,size);
    }
    return 0;
}
