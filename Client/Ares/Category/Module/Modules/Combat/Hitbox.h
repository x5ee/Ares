#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_HITBOX
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_HITBOX

#include "../../Module.h"

class Hitbox : public Module {
public:
    Hitbox(Category* c) : Module("Hitbox", c) {
        //this->isEnabled = true;
    };
public:
    auto onGameMode(GameMode*) -> void override;
    auto onDisable(void) -> void override;
public:
    auto onImGuiOptions(void) -> void override;
public:
    Vec2<float> radius = Vec2<float>(2.f, 2.f);
    std::map<uint8_t, Vec2<float>> collisions;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_COMBAT_HITBOX */