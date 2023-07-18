#ifndef CLIENT_ARES_HOOK_HOOK
#define CLIENT_ARES_HOOK_HOOK

#include "../../SDK/Minecraft.h"
#include "../Manager.h"

class Hook {
public:
    Manager* mgr = nullptr;
public:
    Hook(Manager*);
public:
    virtual auto init(void) -> void {};
};

#endif /* CLIENT_ARES_HOOK_HOOK */