#pragma once
#include "mem.h"
#include "Header.h"

namespace game {
	Mem memory = Mem("csgo.exe");
	uintptr_t client = memory.get_address("client.dll");
	uintptr_t engine = memory.get_address("engine.dll");
};