

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int monthDay [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct Event{
    int distance;
    int day;
    int month;
    int star;
    int id;
    char name[300];
}event[5000];

int lenght = 0;

int cmp(const void *a,const void *b){
    if((*(struct Event *)a).distance > (*(struct Event *)b).distance)return 1;
    else if((*(struct Event *)a).distance < (*(struct Event *)b).distance)return -1;
    else {
        if((*(struct Event *)a).star > (*(struct Event *)b).star)return -1;
        else if((*(struct Event *)a).star < (*(struct Event *)b).star)return 1;
        else {
            if((*(struct Event *)a).id > (*(struct Event *)b).id)return 1;
            else return -1;
        }
    }
}

void printCalendar(int day,int month){
    struct Event tmp[30];
    int sum = 0, distance, importance, i;

    for(i = 0; i < lenght; i++){
        if(month == event[i].month){
            distance = event[i].day - day;
            if(distance >= 0){
                importance = event[i].star - distance + 1;
                if(importance > 0 && importance <= 8){
                    tmp[sum] = event[i];
                    tmp[sum].distance = distance;
                    if(event[i].day == day)tmp[sum].star = 0x7fffffff;
                    else tmp[sum].star = importance;
                    sum++;
                }
            }
        }
        else if((month == event[i].month - 1) || (month == 12 && event[i].month == 1)){
            distance = event[i].day + (monthDay[month] - day);
            importance = event[i].star - distance + 1;
            if(importance > 0 && importance <= 7){
                tmp[sum] = event[i];
                tmp[sum].distance = distance;
                tmp[sum].star = importance;
                sum++;
            }
        }
    }

    qsort(tmp,sum,sizeof(struct Event),cmp);

    printf("Today is:%3d%3d\n",day,month);
    for(i = 0; i < sum; i++){
        printf("%3d%3d ",tmp[i].day,tmp[i].month);
        if(tmp[i].day == day)printf("*TODAY*");
        else {
            int j;
            for(j = 0; j < tmp[i].star; j++)
                printf("*");
            for(;j < 7;j++)
                printf(" ");
        }
        printf(" ");
        printf("%s\n",tmp[i].name);
    }
}

int main(int argc, char const *argv[])
{
    int year,day,month,space = 0;
    char input[500], *p;
    scanf("%d\n",&year);

    if(year % 4 == 0)monthDay[2] = 29;

    while(gets(input)){
        if(input[0] == '#')break;

        p = strtok(input," ");
        p = strtok(NULL," ");

        if(input[0] == 'A'){
            event[lenght].day = atoi(p);
            p = strtok(NULL," ");

            event[lenght].month = atoi(p);
            p = strtok(NULL," ");

            event[lenght].star = atoi(p);
            p = strtok(NULL,"");
            while(*p == ' ')p++;

            strcpy(event[lenght].name,p);
            
            event[lenght].id = lenght;
            lenght++;
        }
        else {
            day = atoi(p);
            p = strtok(NULL," ");

            month = atoi(p);
            p = strtok(NULL," ");

            if(space)printf("\n");
            else space = 1;

            printCalendar(day,month);
        }
    }

    return 0;
}
