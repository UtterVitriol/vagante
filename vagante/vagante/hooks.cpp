#include "hooks.h"
#include "MinHook.h"
#include "Game.h"
#include "GameData.h"

extern Game g_Game;

tPlayer$$Step oPlayer$$Step      = NULL;
uintptr_t     Player$$StepOffset = 0x2e3740;

tPlayer$$Delete oPlayer$$Delete      = NULL;
uintptr_t       Player$$DeleteOffset = 0x2c57e0;

void __fastcall hPlayer$$Step(void *player)
{
    g_Game.pCharacter = (Character *)player;
    return oPlayer$$Step(player);
}

void *__fastcall hPlayer$$Delete(void *player, UINT x)
{
    g_Game.pCharacter = NULL;
    return oPlayer$$Delete(player, x);
}

int
init_hooks ()
{
    int status = MH_OK;

    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"vagante.exe");

    if ((status
         = MH_CreateHook((LPVOID)(moduleBase + Player$$StepOffset), (LPVOID)hPlayer$$Step, (LPVOID *)&oPlayer$$Step))
        != MH_OK)
    {
        return status;
    }

    if ((status = MH_CreateHook(
             (LPVOID)(moduleBase + Player$$DeleteOffset), (LPVOID)hPlayer$$Delete, (LPVOID *)&oPlayer$$Delete))
        != MH_OK)
    {
        return status;
    }

    if ((status = MH_EnableHook(MH_ALL_HOOKS)) != MH_OK)
    {
        return status;
    }

    return status;
}
