#include "clantag.h"
#include "offsets.h"
#include <string>

clantag::clantag(Mem memory, uintptr_t client,uintptr_t engine) {
	DWORD localplayer = memory.Read<uintptr_t>(client + offsets::dwLocalPlayer);
	if (localplayer)
	{
		memory.Write<DWORD>(engine + offsets::dwSetClanTag,"");
	}
}