#include <windows.h>
#include <iostream>

// https://docs.microsoft.com/en-us/windows/win32/memory/creating-named-shared-memory
int main()
{
    HANDLE fileMapping = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,
        FALSE,
        TEXT("FileMappingObject")
    );

    LPCTSTR buff = (LPTSTR)MapViewOfFile(
        fileMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        256
    );

    MessageBox(NULL, buff, TEXT("Process2"), MB_OK);

    UnmapViewOfFile(buff);

    CloseHandle(fileMapping);
}
