#ifndef CLIENT_ARES_HOOK_HOOKS_GAMEMODE_GAMEMODE
#define CLIENT_ARES_HOOK_HOOKS_GAMEMODE_GAMEMODE

#include "../../Hook.h"

class GameModeHook : public Hook {
public:
    GameModeHook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_GAMEMODE_GAMEMODE */