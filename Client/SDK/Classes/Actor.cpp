#include "Actor.h"
#include "../../Mem/Mem.h"

auto Actor::getRuntimeID(void) -> uint64_t {

    using GetRuntimeIDComp = RuntimeIDComponent* (__thiscall*)(void*, EntityId*);
    static auto _GetRuntimeIDComp = (GetRuntimeIDComp)(Mem::findSig("40 53 48 83 EC ? 48 8B DA BA 14 14 ? ?"));

    auto registryBase = *(void**)(this->ctx.registry);
    auto runtimeID = _GetRuntimeIDComp(registryBase, &this->ctx.id);

    return runtimeID->runtimeId;

};

auto Actor::getLevel(void) -> Level* {

    return *(Level**)((uintptr_t)(this) + 0x260);

};

auto Actor::getSize(void) -> Vec2<float> {

    return *(Vec2<float>*)((uintptr_t)(*(uintptr_t**)((uintptr_t)(this) + 0x2A8)) + 0x18);

};