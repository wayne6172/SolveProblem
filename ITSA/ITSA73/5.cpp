#include <cstdio>

int sum;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void DFS(int graph[][100], int i,int j, int m, int n){
    sum += graph[i][j];
    graph[i][j] = 0;

    int nextI,nextJ;

    for(int k = 0; k < 4; k++){
        nextI = i + dir[k][0];
        nextJ = j + dir[k][1];

        if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && graph[nextI][nextJ] > 0)
            DFS(graph,nextI,nextJ,m,n);
    }
}

int main(int argc, char const *argv[])
{
    int m,n,total = 0, max = 0;
    int graph[100][100];
    scanf("%d%d",&n,&m);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&graph[i][j]);
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            sum = 0;
            if(graph[i][j] > 0){
                DFS(graph,i,j,m,n);
                total++;
                if(max < sum)max = sum;
            }
        }

    printf("%d\n%d\n",total,max);
    return 0;
}
