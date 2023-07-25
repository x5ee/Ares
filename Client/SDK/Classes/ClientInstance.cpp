#include "ClientInstance.h"

auto ClientInstance::getLoopbackPacketSender(void) -> LoopbackPacketSender* {

    return *(LoopbackPacketSender**)((uintptr_t)(this) + 0xF0);

};

auto ClientInstance::getPlayer(void) -> Player* {

    using GetPlayer = Player* (__thiscall*)(ClientInstance*);
    auto _GetPlayer = (GetPlayer)(this->VTable[27]);

    return _GetPlayer(this);

};

auto ClientInstance::getbadrefdef(void) -> glmatrixf* {
    
    return (glmatrixf*)((uintptr_t)(this) + 0x330);

};

auto ClientInstance::grabMouse(void) -> void {

    using GrabMouse = void (__thiscall*)(ClientInstance*);
    auto _GrabMouse = (GrabMouse)(this->VTable[306]);

    _GrabMouse(this);

};

auto ClientInstance::releaseMouse(void) -> void {

    using ReleaseMouse = void (__thiscall*)(ClientInstance*);
    auto _ReleaseMouse = (ReleaseMouse)(this->VTable[307]);

    _ReleaseMouse(this);

};

auto ClientInstance::refocusMouse(void) -> void {

    using RefocusMouse = void (__thiscall*)(ClientInstance*);
    auto _RefocusMouse = (RefocusMouse)(this->VTable[308]);

    _RefocusMouse(this);

};

auto ClientInstance::getTopScreenName(void) -> std::string {

    std::string out;

    using GetTopScreenName = void (__thiscall*)(ClientInstance*, std::string*);
    auto _GetTopScreenName = (GetTopScreenName)(this->VTable[137]);

    _GetTopScreenName(this, &out);
    return out;

};