#include "fov_changer.h"
#include "Header.h"

FOV::FOV(Mem memory, uintptr_t client) {

	DWORD localplayer = memory.Read<uintptr_t>(client + offsets::dwLocalPlayer);
	DWORD fov = memory.Read<uintptr_t>(localplayer + offsets::m_iFOV);
	DWORD fov_change = 120;
	bool isScoped = memory.Read<bool>(localplayer + offsets::m_bIsScoped);

	if (localplayer)
	{
		if (isScoped)
		{
			memory.Write<uintptr_t>(localplayer + offsets::m_iFOV, fov_change);
		}
		else
		{
			memory.Write<uintptr_t>(localplayer + offsets::m_iFOV, 90);
		}
	}
}