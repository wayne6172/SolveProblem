#include <cstdio>

int p[1000][8],pSize = 0;
int row[8];

bool col[8],left[15],right[15];

void getQueen(int i){
    if(i == 8){
        for(int j = 0; j < 8; j++){
            p[pSize][j] = row[j];
        }
        pSize++;
        return;
    }

    for(int j = 0; j < 8; j++){
        int ld = j - i + 7;
        int rd = i + j;
        if(!col[j] && !left[ld] && !right[rd]){
            col[j] = left[ld] = right[rd] = true;
            row[i] = j;
            getQueen(i + 1);
            col[j] = left[ld] = right[rd] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    int k,score[8][8],sum,max;
    scanf("%d",&k);
    
    getQueen(0);
    
    while(k--){
        for(int i = 0; i < 64; i++)
            scanf("%d",&score[i / 8][i % 8]);
        
        max = 0;
        for(int i = 0; i < pSize; i++){
            sum = 0;
            for(int j = 0; j < 8; j++)
                sum += score[j][p[i][j]];
            if(sum > max)max = sum;
        }
        printf("%5d\n",max);
    }
    return 0;
}