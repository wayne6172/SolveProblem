#include <cstdio>
#include <cstring>

bool map[243][243];

int pow(int x,int y){
    int tmp = 1;
    while(y--)
        tmp *= x;
    return tmp;
}

void create(int i, int j, int size){
    if(size == 0)
        map[i][j] = true;
    else {
        int space = pow(3,size-1);
        create(i, j, size - 1);
        create(i, j + space * 2,size - 1);
        create(i + space, j + space, size - 1);
        create(i + space * 2, j, size - 1);
        create(i + space * 2, j + space * 2, size - 1);
    }
}

int main(int argc, char const *argv[])
{
    int size,N;
    while(~scanf("%d",&size)){
        if(size == -1)break;
        memset(map,0,sizeof(map));

        create(0,0,size - 1);

        N = pow(3,size - 1);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                if(map[i][j])
                    printf("X");
                else
                    printf(" ");
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}
