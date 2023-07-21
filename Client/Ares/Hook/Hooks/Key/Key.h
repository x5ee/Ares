#ifndef CLIENT_ARES_HOOK_HOOKS_KEY_KEY
#define CLIENT_ARES_HOOK_HOOKS_KEY_KEY

#include "../../Hook.h"

class KeyHook : public Hook {
public:
    KeyHook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_KEY_KEY */