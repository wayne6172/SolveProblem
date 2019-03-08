#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

struct node{
    int x, y;
}point[750];

double map[750][750];

double getDistance(int i,int j){
    int disX = point[i].x - point[j].x;
    int disY = point[i].y - point[j].y;

    return sqrt(disX * disX + disY * disY);
}

double getMinimumSpanningTree(int size){
    double treeDis[size] = {0}, eachMax, ans = 0;
    for(int i = 0; i < size; i++)
        treeDis[i] = DBL_MAX;

    bool isOK[size] = {false};
    int now = 0,next;

    while(true){
        isOK[now] = true;
        eachMax = DBL_MAX;

        bool check = true;
        for(int i = 0; i < size; i++){
            if(!isOK[i]){
                check = false;
                break;
            }
        }

        if(check)break;

        for(int i = 0; i < size; i++){
            treeDis[i] = min(map[now][i],treeDis[i]);

            if(eachMax > treeDis[i] && !isOK[i]){
                next = i;
                eachMax = treeDis[i];
            }
        }
        //printf("%d %d %lf\n",now,next,ans + treeDis[next]);
        now = next;
        ans += treeDis[next];
    }
    return ans;
}

int main(){
    int N,M;

    while(~scanf("%d",&N)){

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                map[i][j] = DBL_MAX;
        
        for(int i = 0; i < N; i++){
            scanf("%d%d",&point[i].x,&point[i].y);
            for(int j = i - 1; j >= 0; j--){
                map[i][j] = map[j][i] = getDistance(i,j);
            }
        }

        scanf("%d",&M);

        int a,b;
        for(int i = 0;i < M; i++){
            scanf("%d%d",&a,&b);
            a--;
            b--;
            map[a][b] = map[b][a] = 0;
        }

        printf("%.2lf\n",getMinimumSpanningTree(N));
    }

    return 0;
}