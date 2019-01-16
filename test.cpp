#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstring>

#define MAX 10000

using namespace std;

struct point{
    int posX,posY,valX,valY;
}node[MAX];

double getDistance(struct point i,struct point j){
    return sqrt(pow(i.posX - j.posX,2) + pow(i.posY - j.posY,2));
}

int cmpX(const void *a,const void *b){
    if((*(struct point *)a).posX > (*(struct point *)b).posX)
        return 1;
    if((*(struct point *)a).posX < (*(struct point *)b).posX)
        return -1;
    
    return 0;
}

int cmpY(const void *a,const void *b){
    if((*(struct point *)a).posY > (*(struct point *)b).posY)
        return 1;
    if((*(struct point *)a).posY < (*(struct point *)b).posY)
        return -1;
    
    return 0;
}

double solveByBrute(){
    
    double min = getDistance(node[0],node[1]);      // 當作極大值
    for(int i = 0; i < MAX - 1; i++){
        for(int j = i + 1; j < MAX; j++){
            double distance = getDistance(node[i],node[j]);
            if(min > distance)min = distance;
        }
    }
    return min;
}

double solveByDivide(struct point P[], struct point Q[], int size){

    
    if(size <= 3){      // return the minimal distance found by the brute-force algorithm
        if(size == 3)
            return min(min(getDistance(P[0],P[1]),getDistance(P[0],P[2])),getDistance(P[1],P[2]));
        else if(size == 2)
            return getDistance(P[0],P[1]);
    }

    // copy the first n/2 points of P to PL

    struct point PL[(size + 1) / 2],QL[(size + 1) / 2];
    struct point PR[size / 2],QR[size / 2];

    int *isOK = (int *)malloc(sizeof(int) * MAX);
    memset(isOK,-1,sizeof(int) * MAX);

    for(int i = 0; i < (size + 1) / 2; i++){
        PL[i] = P[i];
        isOK[P[i].valY] = i;
    }
    
    for(int i = 0, lengthL = 0; i < MAX; i++){
        if(isOK[i] != -1)
            QL[lengthL++] = P[isOK[i]];
    }

    memset(isOK,-1,sizeof(int) * MAX);

    for(int i = (size + 1) / 2; i < size; i++){
        PR[i - (size + 1) / 2] = P[i];
        isOK[P[i].valY] = i;
    }

    for(int i = 0, lengthR = 0; i < MAX; i++){
        if(isOK[i] != -1)
            QR[lengthR++] = P[isOK[i]];
    }

    free(isOK);

    double d = min(solveByDivide(PL,QL,(size + 1) / 2),solveByDivide(PR,QR,size / 2));
    double ans = d;

    for(int i = 0; i < size; i++){
        int tmp[7];
        int length = 0;

        for(int j = i + 1; j < i + 8 && j < size; j++){
            if(abs(Q[i].posX - Q[j].posX) <= d){
                tmp[length++] = j;
            }
        }

        for(int j = 0; j < length; j++){
            double dis = getDistance(Q[i],Q[tmp[j]]);
            if(dis < ans)
                ans = dis;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    time_t start, end;

    for(int i = 0; i < MAX; i++){
        node[i].posX = rand();
        node[i].posY = rand();
    }

    printf("follow by brute\n");

    start = time(NULL);
    printf("distance : %.3lf\n",solveByBrute());
    end = time(NULL);

    printf("%g sec\n",difftime(end,start));

    /////////////////////////////////////////////////////////////


    printf("\nfollow by divide\n");

    struct point P[MAX],Q[MAX];

    qsort(node,MAX,sizeof(struct point),cmpX);
    for(int i = 0; i < MAX; i++){
        node[i].valX = i;
    }

    qsort(node,MAX,sizeof(struct point),cmpY);
    for(int i = 0; i < MAX; i++){
        node[i].valY = i;
        P[node[i].valX] = node[i];
        Q[node[i].valY] = node[i];
    }

    start = time(NULL);
    printf("distance : %.3lf\n",solveByDivide(P,Q,MAX));
    end = time(NULL);

    printf("%g sec\n",difftime(end,start));

    //system("pause");

    return 0;
}
