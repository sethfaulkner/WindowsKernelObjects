#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>


// https://docs.microsoft.com/en-us/windows/win32/memory/creating-named-shared-memory
int main()
{
    HANDLE fileMapping = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        256,
        TEXT("FileMappingObject")
    );


    LPCTSTR buff = (LPTSTR)MapViewOfFile(
        fileMapping,
        FILE_MAP_ALL_ACCESS, 
        0,
        0,
        256
    );

    TCHAR msg[] = TEXT("Hello from process 1.");
    CopyMemory((PVOID)buff, msg, (_tcslen(msg) * sizeof(TCHAR)));
    getchar();

    UnmapViewOfFile(buff);

    CloseHandle(fileMapping);

    return 0;
}
