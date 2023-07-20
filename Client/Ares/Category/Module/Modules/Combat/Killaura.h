#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_KILLAURA
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_KILLAURA

#include "../../Module.h"

class Killaura : public Module {
public:
    Killaura(Category* c) : Module("Killaura", c) {
        //this->isEnabled = true;
    };
public:
    auto onGameMode(GameMode*) -> void override;
    auto onImGuiOptions(void) -> void override;
public:
    float range = 12.f;
    bool attackMobs = true;
    bool attackPlayers = true;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_KILLAURA */