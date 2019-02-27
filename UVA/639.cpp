#include <cstdio>

char input[4][5];
int map[4][4];
int max, sum;

void ping(int i,int j,int n,int To){
    for(int k = i - 1; k >= 0; k--){
        if(input[k][j] == 'X')break;
        if(map[k][j] == 0)
            map[k][j] = To;
    }

    for(int k = i + 1; k < n; k++){
        if(input[k][j] == 'X')break;
        if(map[k][j] == 0)
            map[k][j] = To;
    }

    for(int k = j - 1; k >= 0; k--){
        if(input[i][k] == 'X')break;
        if(map[i][k] == 0)
            map[i][k] = To;
    }

    for(int k = j + 1; k < n; k++){
        if(input[i][k] == 'X')break;
        if(map[i][k] == 0)
            map[i][k] = To;
    }
}

void removePing(int i, int j, int n, int pos){
    for(int k = i - 1; k >= 0; k--){
        if(input[k][j] == 'X')break;
        if(map[k][j] == pos)
            map[k][j] = 0;
    }

    for(int k = i + 1; k < n; k++){
        if(input[k][j] == 'X')break;
        if(map[k][j] == pos)
            map[k][j] = 0;
    }

    for(int k = j - 1; k >= 0; k--){
        if(input[i][k] == 'X')break;
        if(map[i][k] == pos)
            map[i][k] = 0;
    }

    for(int k = j + 1; k < n; k++){
        if(input[i][k] == 'X')break;
        if(map[i][k] == pos)
            map[i][k] = 0;
    }
}

void solve(int pos,int n){
    if(pos == n * n){
        if(sum > max){
            max = sum;
        }
        return;
    }

    if(input[pos / n][pos % n] == '.'){
        if(!map[pos / n][pos % n]){
            ping(pos / n, pos % n, n, pos + 1);
            sum++;
            solve(pos + 1,n);
            removePing(pos / n, pos % n, n, pos + 1);
            sum--;
        }
    }
    solve(pos + 1,n);
}

int main(int argc, char const *argv[])
{
    int n;
    while(~scanf("%d",&n)){
        if(n == 0)break;
        for(int i = 0; i < n; i++){
            scanf("%s",input[i]);
            for(int j = 0; j < n; j++)
                map[i][j] = 0;
        }

        max = 0, sum = 0; 
        solve(0,n);
        printf("%d\n",max);
    }
    return 0;
}
