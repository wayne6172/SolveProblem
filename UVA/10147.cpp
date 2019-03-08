#include <cstdio>
#include <cfloat>
#include <cmath>

struct node{
    int x,y;
}city[750];

double map[750][750];

double getDis(int x1,int y1,int x2,int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve(int size){
    bool isOK[size] = {false}, notHave = true;
    int front[size] = {0};
    double cityDis[size] = {0},nowMin;
    for(int i = 0; i < size; i++)
        cityDis[i] = DBL_MAX;

    
    int now = 0,next;
    bool exit;
    while(true){
        exit = true;
        isOK[now] = true;
        nowMin = DBL_MAX;
        for(int i = 0; i < size; i++){
            if(!isOK[i]){
                exit = false;
                break;
            }
        }

        if(exit)break;

        for(int i = 0; i < size; i++){
            if(cityDis[i] > map[now][i]){
                cityDis[i] = map[now][i];
                front[i] = now;
            }
            if(nowMin > cityDis[i] && !isOK[i]){
                next = i;
                nowMin = cityDis[i];
            }
        }

        if(map[front[next]][next] != 0){
            printf("%d %d\n",front[next] + 1,next + 1);
            notHave = false;
        }
        now = next;
    }

    if(notHave)
        printf("No new highways need\n");
}

int main(int argc, char const *argv[])
{
    int T,N,M,a,b;
    bool space = false;
    scanf("%d",&T);

    while(T--){
        if(space)printf("\n");
        else space = true;

        scanf("%d",&N);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                map[i][j] = DBL_MAX;

        for(int i = 0; i < N; i++){
            scanf("%d%d",&city[i].x,&city[i].y);
            for(int j = i - 1; j >= 0; j--){
                map[i][j] = map[j][i] = getDis(city[i].x,city[i].y,city[j].x,city[j].y);
            }
        }

        scanf("%d",&M);
        for(int i = 0; i < M; i++){
            scanf("%d%d",&a,&b);
            a--;
            b--;
            map[a][b] = map[b][a] = 0;
        }

        solve(N);
    }
    return 0;
}
