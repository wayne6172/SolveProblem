#include <cstdio>
#include <cstring>

bool map[25][25];

int find(int i,int n){
    int max = 0, sum;
    for(int j = 0; j < n; j++){
        if(map[i][j]){
            map[i][j] = map[j][i] = false;
            sum = find(j,n);
            if(sum > max)max = sum;
            map[i][j] = map[j][i] = true;
        }
    }
    return max + 1;
}

int main(int argc, char const *argv[])
{
    int n,m,x,y,max,sum;
    while(~scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0)break;
        memset(map,0,sizeof(map));

        while(m--){
            scanf("%d%d",&x,&y);
            map[x][y] = map[y][x] = true;
        }

        max = 0;
        for(int i = 0; i < n; i++){
            sum = find(i,n);
            if(sum > max)max = sum;
        }
        printf("%d\n",max - 1);
    }
    return 0;
}
