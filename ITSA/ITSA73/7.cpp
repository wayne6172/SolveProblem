#include <cstdio>

int sum;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void DFS(int graph[][100], int i,int j, int m, int n){
    sum++;
    graph[i][j] = -1;

    int nextI,nextJ;

    for(int k = 0; k < 4; k++){
        nextI = i + dir[k][0];
        nextJ = j + dir[k][1];

        if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && graph[nextI][nextJ] == 0)
            DFS(graph,nextI,nextJ,m,n);
    }
}

int main(int argc, char const *argv[])
{
    int T,n,size,a,b;
    scanf("%d",&T);
    while(T--){
        int graph[100][100] = {0};
        scanf("%d%d",&n,&size);
        sum = 0;

        while(size--){
            scanf("%d%d",&a,&b);
            graph[a - 1][b - 1] = -1;
        }

        scanf("%d%d",&a,&b);
        DFS(graph,a - 1,b - 1,n,n);

        printf("%d\n",sum);
    }
    
    return 0;
}
