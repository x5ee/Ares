#include "Client/Client.h"

auto init(HINSTANCE hInstance) -> void {

    auto ares = new Client("Ares");

    auto instance = MC::getClientInstance();
    auto player = (instance ? instance->getPlayer() : nullptr);

    if(!player)
        return;

    Utils::debugOutput(std::string("Runtime ID: " + std::to_string(player->getRuntimeID())));
    
    std::ostringstream o;
    o << std::hex << instance << std::endl;

    if(player)
        o << std::hex << player;

    Utils::debugOutput(o.str());

};

auto WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) -> BOOL {

    if(fdwReason == 1)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);

    return 1;

};