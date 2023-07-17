#include "Client/Client.h"

auto init(HINSTANCE hInstance) -> void {

    auto ares = new Client("Ares");

    auto instance = MC::getClientInstance();
    auto player = (instance ? instance->getPlayer() : nullptr);

    auto msg = std::string(ares->name + ": Hello, World!");
    
    if(player)
        player->displayClientMessage(&msg);

};

auto WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) -> BOOL {

    if(fdwReason == 1)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);

    return 1;

};