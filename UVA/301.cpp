#include <cstdio>

int can[7];
int start[22],end[22],people[22];
int max, sum;

void solve(int i,int t){
    if(i == t){
        if(sum > max)max = sum;
    }
    else {
        bool canChoose = true;

        for(int j = start[i]; j < end[i]; j++){
            if(can[j] - people[i] < 0){
                canChoose = false;
                break;
            }
        }

        if(canChoose){
            for(int j = start[i]; j < end[i]; j++){
                can[j] -= people[i];
                sum += people[i];
            }
            solve(i + 1, t);

            for(int j = start[i]; j < end[i]; j++){
                can[j] += people[i];
                sum -= people[i];
            }
            solve(i + 1, t);
        }
        else solve(i + 1, t);
    }
}

int main(int argc, char const *argv[])
{
    int N,B,t;
    while(~scanf("%d%d%d",&N,&B,&t)){
        if(N == 0 && B == 0 && t == 0)break;
        for(int i = 0; i < B; i++)
            can[i] = N;
        for(int i = 0; i < t; i++)
            scanf("%d%d%d",&start[i],&end[i],&people[i]);

        max = sum = 0;
        solve(0,t);
    
        printf("%d\n",max);
    }
    return 0;
}
