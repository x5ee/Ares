#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_PLAYER_AUTOSPRINT
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_PLAYER_AUTOSPRINT

#include "../../Module.h"

class AutoSprint : public Module {
public:
    AutoSprint(Category* c) : Module("AutoSprint", c) {
        this->isEnabled = true;
    };
public:
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_PLAYER_AUTOSPRINT */