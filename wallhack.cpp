#include "wallhack.h"
#include "offsets.h"
#include "mem.h"

WALL::WALL(Mem mem, uintptr_t clientBase,uintptr_t engine) {

	DWORD glowObj = mem.Read<DWORD>(clientBase + offsets::dwGlowObjectManager);
	DWORD myTeam = mem.Read<DWORD>(mem.Read<DWORD>(clientBase + offsets::dwLocalPlayer) + offsets::m_iTeamNum);

	for (int x = 1; x < 32; x++)
	{
		DWORD player = mem.Read<DWORD>(clientBase + offsets::dwEntityList + x * 0x10);
		if (player == 1)
			continue;

		bool dormant = mem.Read<bool>(player + 0xED);
		if (dormant)
			continue;

		DWORD team = mem.Read<DWORD>(player + offsets::m_iTeamNum);
		if (team != 2 && team != 3)
			continue;

		DWORD currentGlowIndex = mem.Read<DWORD>(player + offsets::m_iGlowIndex);

		if (team != myTeam)
		{
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0x4, 255); // red
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0x8, 0); // green
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0xC, 0); // blue
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0x10, 255);
			mem.Write<bool>(glowObj + currentGlowIndex * 0x38 + 0x24, true);
			mem.Write<bool>(glowObj + currentGlowIndex * 0x38 + 0x25, false);
		}
		else
		{
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0x4, 0); // red
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0x8, 0); // green
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0xC, 255); // blue
			mem.Write<float>(glowObj + currentGlowIndex * 0x38 + 0x10, 255);
			mem.Write<bool>(glowObj + currentGlowIndex * 0x38 + 0x24, true);
			mem.Write<bool>(glowObj + currentGlowIndex * 0x38 + 0x25, false);
		}
	}
}