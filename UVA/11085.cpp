#include <cstdio>
#define MAX 8

int queenCol[MAX];
int storeAns[92][MAX];
int sum;

int abs(int n){
    return n < 0 ? -n : n;
}

void store(){
    for(int i = 0; i < MAX; i++){
        storeAns[sum][queenCol[i]] = i + 1;
    }
    sum++;
}

void r(int row){
    if(row == MAX){
        store();
        return;
    }

    for(int i = 0; i < MAX; i++){
        bool can = true;
        for(int j = 0; j < row; j++){
            if(queenCol[j] == i || abs(j - row) == abs(queenCol[j] - i))can = false;
        }

        if(can){
            queenCol[row] = i;
            r(row + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    sum = 0;
    r(0);

    int data[MAX], t = 0;
    while(scanf("%d",&data[0])!=EOF){
        int min = 0x7fffffff, test;
        for(int i = 1; i < MAX; i++)
            scanf("%d", &data[i]);
        
        
        for(int i = 0; i < sum; i++){
            test = 0;
            for(int j = 0; j < MAX; j++){
                if(storeAns[i][j] != data[j])
                    test++;
            }
            if(min > test)min = test;
        }

        printf("Case %d: %d\n", ++t, min);
    }
    
    return 0;
}
