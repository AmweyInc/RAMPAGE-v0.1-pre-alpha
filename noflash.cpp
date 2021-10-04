#include "Header.h"
#include "mem.h"
#include "offsets.h"
#include "noflash.h"

NOFLASH::NOFLASH(Mem mem, uintptr_t client) {
	DWORD localPlayer = mem.Read<uintptr_t>(client + offsets::dwLocalPlayer);
	
	if (localPlayer) {
		DWORD flashDuration = mem.Read<uintptr_t>(localPlayer + offsets::m_flFlashDuration);
		if (flashDuration > 0)
		{
			mem.Write<DWORD>(localPlayer + offsets::m_flFlashDuration,0);
		}
	}
}