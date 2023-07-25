#include "MovementProxy.h"

auto MovementProxy::isOnGround(void) -> bool {

    using IsOnGround = bool (__thiscall*)(MovementProxy*);
    auto _IsOnGround = (IsOnGround)(this->VTable[39]);

    return _IsOnGround(this);

};

auto MovementProxy::setOnGround(bool state) -> void {

    using SetOnGround = void (__thiscall*)(MovementProxy*, bool);
    auto _SetOnGround = (SetOnGround)(this->VTable[40]);

    _SetOnGround(this, state);

};

auto MovementProxy::getHealth(void) -> int {

    using GetHealth = int (__thiscall*)(MovementProxy*);
    auto _GetHealth = (GetHealth)(this->VTable[43]);

    return _GetHealth(this);

};