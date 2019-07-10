#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

DWORD Sum;

DWORD WINAPI Summation(LPVOID Parm){
    DWORD Upper = *(DWORD *)Parm;

    DWORD i;
    for(i = 0; i <= Upper; i++){
        //printf("%d\n",i);
        Sum += i;
    }
    
    return 0;
}

int main(int argc, char *argv[]){
    DWORD ThreadID;
    HANDLE ThreadHandle;
    int Param;

    if(argc != 2){
        fprintf(stderr,"An integer parameter is required\n");
        return -1;
    }

    Param = atoi(argv[1]);
    if(Param < 0){
        fprintf(stderr,"An integer >= 0 is required\n");
        return -1;
    }

    ThreadHandle = CreateThread(NULL,0,Summation,&Param,0,&ThreadID);
    
    if(ThreadHandle != NULL){
        printf("Create Thread\n");
        WaitForSingleObject(ThreadHandle,1000);

        CloseHandle(ThreadHandle);

        printf("Sum = %d\n",Sum);
    }

    return 0;
}