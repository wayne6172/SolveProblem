#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    HANDLE hFile, hMapFile;
    LPVOID lpMapAddress;

    hFile = CreateFile("temp.txt",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    hMapFile = CreateFileMapping(hFile,
        NULL,
        PAGE_READWRITE,
        0,
        0,
        TEXT("SharedObject")
    );

    lpMapAddress = MapViewOfFile(hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        0
    );

    sprintf(lpMapAddress,"Shared memory message");
    
    UnmapViewOfFile(lpMapAddress);
    CloseHandle(hFile);
    CloseHandle(hMapFile);


    return 0;
}
