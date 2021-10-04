#include "Header.h"
#include "mem.h"
#include "offsets.h"
#include "bhop.h"

BHOP::BHOP(Mem mem, uintptr_t client) {
    DWORD localPlayer = mem.Read<uintptr_t>(client + offsets::dwLocalPlayer);

    if (localPlayer)
    {
        bool onGround = mem.Read<bool>(localPlayer + offsets::m_fFlags);

        if (GetAsyncKeyState(VK_SPACE) && onGround & (1 << 0))
        {
            mem.Write<BYTE>(client + offsets::dwForceJump, 6);
        }
    }

    std::this_thread::sleep_for(std::chrono::nanoseconds(58));
}