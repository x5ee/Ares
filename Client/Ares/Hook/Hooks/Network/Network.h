#ifndef CLIENT_ARES_HOOK_HOOKS_NETWORK_NETWORK
#define CLIENT_ARES_HOOK_HOOKS_NETWORK_NETWORK

#include "../../Hook.h"

class NetworkHook : public Hook {
public:
    NetworkHook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_NETWORK_NETWORK */