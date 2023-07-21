#ifndef CLIENT_ARES_HOOK_HOOKS_ENTITYTICK_ENTITYLEVELTICK
#define CLIENT_ARES_HOOK_HOOKS_ENTITYTICK_ENTITYLEVELTICK

#include "../../Hook.h"

class EntityLevelTickHook : public Hook {
public:
    EntityLevelTickHook(Manager* mgr) : Hook(mgr) {
        //this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_ENTITYTICK_ENTITYLEVELTICK */