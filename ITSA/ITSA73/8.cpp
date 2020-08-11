#include <cstdio>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int n;
    int a,b,x,y;
    int array[500][500];

    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&array[i][j]);

    int max = 0;

    for(int k = 0; k < n; k++){
        max = 0;
        for(a = 0; a < n; a++){
            for(b = 0; b < n; b++){
                if(max < array[a][b]){
                    max = array[a][b];
                    x = a;
                    y = b;
                }
            }
        }

        printf("boy %d pair with girl %d\n",x + 1,y + 1);

        for(int i = 0; i < n; i++)
            array[x][i] = array[i][y] = 0;
    }

    return 0;
}
