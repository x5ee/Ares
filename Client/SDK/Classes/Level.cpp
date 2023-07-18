#include "Level.h"

auto Level::getRuntimeEntity(uint64_t runtimeId, bool p2) -> Actor* {

    using GetRuntimeEntity = Actor* (__thiscall*)(Level*, uint64_t, bool);
    auto _GetRuntimeEntity = (GetRuntimeEntity)(this->VTable[52]);

    return _GetRuntimeEntity(this, runtimeId, p2);

};