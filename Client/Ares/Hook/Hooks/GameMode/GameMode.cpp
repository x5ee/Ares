#include "GameMode.h"

typedef void (__thiscall* GameModeTick)(GameMode*);
GameModeTick _GameModeTick;

Manager* gmManager = nullptr;

auto GameModeTickCallback(GameMode* GM) -> void {

    if(gmManager) {

        // WIP

    };

    _GameModeTick(GM);

};

auto GameModeHook::init(void) -> void {

    auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 89 01  48 89 51 ? 48 C7 41 10");

    if(!sig)
        return Utils::debugOutput("Failed to find signature for GameMode VTable!");
    
    auto offset = *(int*)(sig + 3);
    auto VTable = (uintptr_t**)(sig + offset + 7);

    if(MH_CreateHook((void*)VTable[8], &GameModeTickCallback, reinterpret_cast<LPVOID*>(&_GameModeTick)) == MH_OK)
        MH_EnableHook((void*)VTable[8]);
    else
        Utils::debugOutput("Failed to create detour for GameMode::tick");

};