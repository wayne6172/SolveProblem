#include <cstdio>

int main(int argc, char const *argv[])
{
    int x,y,tx,ty,mask = 0;
    double min;
    double hourMin, ans;
    scanf("%d%d",&x,&y);
    

    for(int i = x; i < y; i++){
        for(int j = 0; j < 60; j++){
            min = j * 6;
            hourMin = (double)j * ((double)360 / 12 / 60) + (i % 12) * (360 / 12);

            if(hourMin > min){
                ans = (hourMin - min);
            }
            else {
                ans = min - hourMin;
            }

            if(ans > 180)
                ans = 360 - ans;

            if(ans >= 88 && ans <= 92)
                printf("%02d:%02d degree=%.2lf\n",i ,j ,ans);
        }
    }

    if(y == 3 || y == 9 || y == 15 || y == 21)
        printf("%02d:00 degree=90.00\n",y);

    return 0;
}
