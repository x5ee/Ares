#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_MOVE_AIRJUMP
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_MOVE_AIRJUMP

#include "../../Module.h"

class AirJump : public Module {
public:
    AirJump(Category* c) : Module("AirJump", c) {
        //
    };
public:
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_MOVE_AIRJUMP */