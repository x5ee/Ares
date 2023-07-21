#include "ClientInstance.h"

auto ClientInstance::getPlayer(void) -> Player* {

    using GetPlayer = Player* (__thiscall*)(ClientInstance*);
    auto _GetPlayer = (GetPlayer)(this->VTable[27]);

    return _GetPlayer(this);

};

auto ClientInstance::getbadrefdef(void) -> glmatrixf* {
    
    return (glmatrixf*)((uintptr_t)(this) + 0x330);

};

auto ClientInstance::getTopScreenName(void) -> std::string {

    std::string out;

    using GetTopScreenName = void (__thiscall*)(ClientInstance*, std::string*);
    auto _GetTopScreenName = (GetTopScreenName)(this->VTable[137]);

    _GetTopScreenName(this, &out);
    return out;

};