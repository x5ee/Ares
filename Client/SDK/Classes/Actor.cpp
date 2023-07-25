#include "Actor.h"
#include "../../Mem/Mem.h"

auto Actor::getRuntimeID(void) -> uint64_t {

    using GetRuntimeIDComp = RuntimeIDComponent* (__thiscall*)(void*, EntityId*);
    static auto _GetRuntimeIDComp = (GetRuntimeIDComp)(Mem::findSig("40 53 48 83 EC ? 48 8B DA BA 14 14 ? ?"));

    auto registryBase = *(void**)(this->ctx.registry);
    auto runtimeID = _GetRuntimeIDComp(registryBase, &this->ctx.id);

    return runtimeID->runtimeId;

};

auto Actor::getMovementProxy(void) -> MovementProxy* {

    using GetMovementProxyComponent = void* (__thiscall*)(void*, EntityId*);
    static auto _GetMovementProxyComponent = (GetMovementProxyComponent)(Mem::findSig("40 53 48 83 EC ? 48 8B DA BA ? ? ? ? E8 ? ? ? ? 8B 0B 4C 8B D0 44 8B C1 8B C1 41 81 E0 ? ? ? ? 49 C1 E8 ? 4D 8B 4A ? 49 8B 52 ? 49 2B D1 48 C1 FA ? 4C 3B C2 73 ? 4B 8B 14 C1 48 85 D2 74 ? 25 ? ? ? ? 4C 8D 04 82 4D 85 C0 74 ? 81 E1 ? ? ? ? 41 33 08 81 F9 ? ? ? ? 73 ? 8B 04 82 49 8B 4A ? 25 ? ? ? ? 8B D0 83 E0 ? 48 C1 EA ? 48 C1 E0 ? 48 03 04 D1 48 83 C4 ? 5B C3 33 C0 48 83 C4 ? 5B C3 CC 40 53 48 83 EC ? 48 8B 01 48 8B D9 BA ? ? ? ? 48 8B 08 E8 ? ? ? ? 8B 4B ? 8B D1 81 E2 ? ? ? ? 44 8B C2 4C 8B 48 ? 48 8B 40 ? 49 2B C1 49 C1 E8 ? 48 C1 F8 ? 4C 3B C0 73 ? 4B 8B 04 C1 48 85 C0 74 ? 81 E2 ? ? ? ? 4C 8D 04 90 4D 85 C0 74 ? 81 E1 ? ? ? ? 41 33 08 81 F9 ? ? ? ? 73 ? B0 ? 48 83 C4 ? 5B C3 32 C0 48 83 C4 ? 5B C3 CC CC CC CC CC CC CC CC 40 53 48 83 EC ? 48 8B 01"));

    auto registryBase = *(void**)(this->ctx.registry);
    auto moveProxyComp = _GetMovementProxyComponent(registryBase, &this->ctx.id);

    return *(MovementProxy**)(moveProxyComp);

};

auto Actor::getLevel(void) -> Level* {

    return *(Level**)((uintptr_t)(this) + 0x260);

};

auto Actor::getSize(void) -> Vec2<float> {

    return *(Vec2<float>*)((uintptr_t)(*(uintptr_t**)((uintptr_t)(this) + 0x2A8)) + 0x18);

};

auto Actor::isAttackableMob(void) -> bool {

    auto typeId = this->getEntityTypeId();

    switch(typeId) {

        case 64: /* item */
            return false;
        break;

        case 69: /* dropped orb */
            return false;
        break;

        case 65: /* primed tnt */
            return false;
        break;

        case 66: /* falling block */
            return false;
        break;

        case 67: /* moving block */
            return false;
        break;

        case 61: /* armor stand */
            return false;
        break;

        case 68: /* xp bottle */
            return false;
        break;

        case 70: /* eye of ender signal */
            return false;
        break;

        case 71: /* ender crystal */
            return false;
        break;

        case 72: /* fireworks rocket */
            return false;
        break;

        case 73: /* thrown trident */
            return false;
        break;

        case 76: /* shulker bullet */
            return false;
        break;

        case 77: /* fishing hook */
            return false;
        break;

        case 79: /* dragon fireball */
            return false;
        break;

        case 80: /* arrow */
            return false;
        break;

        case 81: /* snowball */
            return false;
        break;

        case 82: /* egg */
            return false;
        break;

        case 83: /* painting */
            return false;
        break;

        case 84: /* minecart */
            return false;
        break;

        case 85: /* ghast fireball */
            return false;
        break;

        case 86: /* splash potion */
            return false;
        break;

        case 87: /* thrown ender pearl */
            return false;
        break;

        case 88: /* leash knot */
            return false;
        break;

        case 89: /* wither skull */
            return false;
        break;

        case 90: /* boat */
            return false;
        break;

        case 91: /* wither skull dangerous */
            return false;
        break;

        case 93: /* lightning bolt */
            return false;
        break;

        case 94: /* small fireball */
            return false;
        break;

        case 95: /* area effect cloud */
            return false;
        break;

        case 96: /* hopper minecart */
            return false;
        break;

        case 97: /* tnt minecart */
            return false;
        break;

        case 98: /* chest minecart */
            return false;
        break;

        case 100: /* command block minecart */
            return false;
        break;

        case 101: /* lingering potion */
            return false;
        break;

        case 102: /* llama spit */
            return false;
        break;

        case 103: /* evocation fang */
            return false;
        break;

        case 106: /* ice bomb */
            return false;
        break;

        case 107: /* balloon */
            return false;
        break;

        case 218: /* chest boat */
            return false;
        break;

        case 117: /* shield */
            return false;
        break;

        case 120: /* elder guardian ghost */
            return false;
        break;

        case 62: /* tripod camera */
            return false;
        break;

        case 78: /* chalkboard */
            return false;
        break;

    };

    return true;

};