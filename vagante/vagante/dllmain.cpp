#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <cstdio>

#ifdef _WIN64
#include "imgui_run64.h"
#else
#include "imgui_run32.h"
#endif

#include "MinHook.h"
#include "hooks.h"
#include "Game.h"

Game g_Game;

int WINAPI
HackThread (HMODULE hModule)
{
    AllocConsole();
    FILE *fp = NULL;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    int status = 0;

    if (MH_OK != (MH_Initialize()))
    {
        goto END;
    }

    if (MH_OK != (status = init_hooks()))
    {
        goto END;
    }

    imgui_run();

END:
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();
    fclose(fp);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY
DllMain (HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
