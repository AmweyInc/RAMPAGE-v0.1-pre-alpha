#include "radar.h"
#include "offsets.h"
#include "mem.h"

RADAR::RADAR(Mem mem, uintptr_t client) {
    DWORD pLocal = mem.Read<uintptr_t>(client + offsets::dwLocalPlayer);
    DWORD localHp = mem.Read<DWORD>(pLocal + offsets::m_iHealth);
    DWORD localTeam = mem.Read<DWORD>(pLocal + offsets::m_iTeamNum);


    for (DWORD i = 0; i < 64; i++) {
        DWORD pEnt = mem.Read<DWORD>(client + offsets::dwEntityList + (i - 1) * 0x10);
        DWORD entHp = mem.Read<DWORD>(pEnt + offsets::m_iHealth);
        if (!entHp)
            continue;

        DWORD entTeam = mem.Read<DWORD>(pEnt + offsets::m_iTeamNum);
        if (entTeam == localTeam)
            continue;

        BOOL entSpotted = mem.Read<DWORD>(pEnt + offsets::m_bSpotted);
        if (entSpotted)
            continue;

        mem.Write(pEnt + offsets::m_bSpotted, TRUE);
    }
}