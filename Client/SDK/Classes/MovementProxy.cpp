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

auto MovementProxy::setCollision(bool state) -> void {

    using SetCollision = void (__thiscall*)(MovementProxy*, bool);
    auto _SetCollision = (SetCollision)(this->VTable[48]);

    _SetCollision(this, state);

};

auto MovementProxy::setRotation(Vec2<float>* rot) -> void {

    using SetRotation = void (__thiscall*)(MovementProxy*, Vec2<float>*);
    auto _SetRotation = (SetRotation)(this->VTable[74]);

    _SetRotation(this, rot);

};