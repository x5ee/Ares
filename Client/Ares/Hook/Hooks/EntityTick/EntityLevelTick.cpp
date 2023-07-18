#include "EntityLevelTick.h"

typedef void (__thiscall* EntityTick)(Actor*);
EntityTick _EntityTick;

Manager* entTickMgr = nullptr;

auto EntityTickCallback(Actor* entity) {

    if(entTickMgr != nullptr) {

        auto runtimeID = entity->getRuntimeID();
        entTickMgr->entityMap.emplace(runtimeID, entity);

    };

    _EntityTick(entity);

};

auto EntityLevelTickHook::init(void) -> void {

    entTickMgr = this->mgr;

    auto sig = Mem::findSig("48 83 EC 28 48 8B 89 60 02 00 00");

    if(!sig)
        return Utils::debugOutput("Failed to find signature for EntityLevelTick hook!");
    
    if(MH_CreateHook((void*)sig, &EntityTickCallback, reinterpret_cast<LPVOID*>(&_EntityTick)) != MH_OK)
        return Utils::debugOutput("Failed to detour for EntityLevelTick hook!");
    
    MH_EnableHook((void*)sig);

};