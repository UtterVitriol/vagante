#pragma once

#include <WinSock2.h>

typedef void(__fastcall *tPlayer$$Step)(void *player);
typedef void *(__fastcall *tPlayer$$Delete)(void *player, UINT x);

int init_hooks();
