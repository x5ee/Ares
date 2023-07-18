#include "Client/Client.h"

typedef void ( __thiscall* EntityLevelTick ) ( Actor* );
EntityLevelTick _EntityLevelTick;

std::map<uint64_t, Actor*> entityMap;

auto EntityLevelTickCallback(Actor* entity) -> void {

    if(entity && entity->ctx.id.id) {

        auto runtimeID = entity->getRuntimeID();

        if(!entityMap.contains(runtimeID)) {
            
            entityMap[runtimeID] = entity;
            Utils::debugOutput(std::string("New Entity: " + std::to_string(runtimeID)));

        };

    };

    _EntityLevelTick(entity);

};

auto init(HINSTANCE hInstance) -> void {

    auto ares = new Client("Ares");
};

auto WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) -> BOOL {

    if(fdwReason == 1)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);

    return 1;

};