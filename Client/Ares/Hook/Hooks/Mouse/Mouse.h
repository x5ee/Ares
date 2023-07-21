#ifndef CLIENT_ARES_HOOK_HOOKS_MOUSE_MOUSE
#define CLIENT_ARES_HOOK_HOOKS_MOUSE_MOUSE

#include "../../Hook.h"

class MouseHook : public Hook {
public:
    MouseHook(Manager* mgr) : Hook(mgr) {
        //this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_MOUSE_MOUSE */