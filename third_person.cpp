#include "third_person.h"
#include "offsets.h"
#include "mem.h"

THIRDPERSON::THIRDPERSON(Mem mem, uintptr_t client) {
	DWORD localplayer = mem.Read<uintptr_t>(client + offsets::dwLocalPlayer);
	if (localplayer)
	{
		mem.Write<DWORD>(localplayer + offsets::m_iObserverMode, 1);
	}
}