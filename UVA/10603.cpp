#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

struct state{
    int a,b,cost;
    state(int x,int y,int z):a(x),b(y),cost(z) {}
};

using namespace std;

int target;
int solve(int sizeA,int sizeB,int sizeC,int all){
    int dp[201][201];
    for(int i = 0; i <= sizeA; i++){
        for(int j = 0; j <= sizeB; j++)
            dp[i][j] = 2000000000;
    }

    queue<state> q;

    state tmp(0,0,0);
    q.push(tmp);

    while(!q.empty()){
        state tmp = q.front();
        dp[tmp.a][tmp.b] = dp[tmp.a][tmp.b] > tmp.cost ? tmp.cost : dp[tmp.a][tmp.b];

        int nowA = tmp.a;
        int nowB = tmp.b;
        int nowC = all - tmp.a - tmp.b;
        int move,tA,tB,tC;
        
        if(nowA != 0 && nowB != sizeB){     //A可給B
            move = nowA < (sizeB - nowB) ? nowA : (sizeB - nowB);
            tA = nowA - move;
            tB = nowB + move;
            tC = nowC;

            if(dp[tA][tB] > tmp.cost + move){
                state t(tA,tB,tmp.cost + move);
                q.push(t);
            }
        }

        if(nowA != 0 && nowC != sizeC){     //A可給C
            move = nowA < (sizeC - nowC) ? nowA : (sizeC - nowC);
            tA = nowA - move;
            tB = nowB;
            tC = nowC + move;

            if(dp[tA][tB] > tmp.cost + move){
                state t(tA,tB,tmp.cost + move);
                q.push(t);
            }
        }

        if(nowB != 0 && nowA != sizeA){     //B可給A
            move = nowB < (sizeA - nowA) ? nowB : (sizeA - nowA);
            tA = nowA + move;
            tB = nowB - move;
            tC = nowC;

            if(dp[tA][tB] > tmp.cost + move){
                state t(tA,tB,tmp.cost + move);
                q.push(t);
            }
        }

        if(nowB != 0 && nowC != sizeC){     //B可給C
            move = nowB < (sizeC - nowC) ? nowB : (sizeC - nowC);
            tA = nowA;
            tB = nowB - move;
            tC = nowC + move;

            if(dp[tA][tB] > tmp.cost + move){
                state t(tA,tB,tmp.cost + move);
                q.push(t);
            }
        }

        if(nowC != 0 && nowA != sizeA){     //C可給A
            move = nowC < (sizeA - nowA) ? nowC : (sizeA - nowA);
            tA = nowA + move;
            tB = nowB;
            tC = nowC - move;

            if(dp[tA][tB] > tmp.cost + move){
                state t(tA,tB,tmp.cost + move);
                q.push(t);
            }
        }

        if(nowC != 0 && nowB != sizeB){     //C可給B
            move = nowC < (sizeB - nowB) ? nowC : (sizeB - nowB);
            tA = nowA;
            tB = nowB + move;
            tC = nowC - move;

            if(dp[tA][tB] > tmp.cost + move){
                state t(tA,tB,tmp.cost + move);
                q.push(t);
            }
        }

        q.pop();
    }

    int min;
    bool find = false;
    while(!find){
        min = 2000000000;
        for(int i = 0; i <= sizeA; i++){
            for(int j = 0; j <= sizeB; j++){
                //printf("%03d ",dp[i][j]);
                if((i == target || j == target || all - i - j == target)){
                    if(min > dp[i][j]){
                        min = dp[i][j];
                        find = true;
                    }
                }
            }
            //printf("\n");
        }
        target--;
    }
    

    return min;
}

int main(){
    int t,a,b,c;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&target);

        printf("%d ",solve(a,b,c,c));
        printf("%d\n",target + 1);
    }
}