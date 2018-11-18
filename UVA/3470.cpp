#include <cstdio>

int table[500][100];

int main(int argc, char const *argv[])
{
    int N,D;
    while(scanf("%d%d",&N,&D) && N && D){
        for(int i = 0; i < D; i++){
            for(int j = 0; j < N; j++){
                scanf("%d",&table[i][j]);
            }
        }

        int k,t;
        for(k = 0; k < N; k++){
            for(t = 0; t < D; t++){
                if(table[t][k] == 0)break;
            }
            if(t == D)break;
        }

        if(k == N)printf("no\n");
        else printf("yes\n");
    }

    return 0;
}
