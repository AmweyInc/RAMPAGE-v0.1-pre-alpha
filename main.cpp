#include "mem.h"
#include "offsets.h"
#include "Header.h"
#include "bhop.h"
#include "radar.h"
#include "wallhack.h"
#include "noflash.h"
#include "third_person.h"
#include "mem_ata.h"
#include "fov_changer.h"
#include "clantag.h"

int main()
{
    Mem memory = game::memory;
    uintptr_t client = game::client;
    uintptr_t engine = game::engine;
    system("Color a");
    SetConsoleTitleA("RAMPAGE");
    std::cout << "Hello,i am RAMPAGE\n" << std::endl;
    std::cout << "Process id: " << memory.get_id_process() << std::endl;
    std::cout << "client.dll -> " << "0x" << std::hex << client << std::dec << std::endl;
    std::cout << "engine.dll -> " << "0x" << std::hex << engine << std::dec << std::endl;
    std::cout << "prealpha version 0.1\n" << std::endl;
    std::cout << " " << std::endl;

    while (true)
    {
        clantag clantag(memory,client,engine);
        THIRDPERSON thirdperson(memory, client);
        WALL wallhack(memory, client, engine);
        FOV fov(memory, client);
        NOFLASH noflash(memory, client);
        RADAR radar(memory, client);
        BHOP bhop(memory, client);
    }
}