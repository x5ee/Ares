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
public:
    bool attackMobs = true;
    bool attackPlayers = true;
public:
    bool sortByHealth = true;
public:
    std::chrono::time_point<std::chrono::system_clock> time = std::chrono::system_clock::now();
    int msDelay = 50;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_KILLAURA */