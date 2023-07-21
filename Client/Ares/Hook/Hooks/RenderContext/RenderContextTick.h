#ifndef CLIENT_ARES_HOOK_HOOKS_RENDERCONTEXT_RENDERCONTEXTTICK
#define CLIENT_ARES_HOOK_HOOKS_RENDERCONTEXT_RENDERCONTEXTTICK

#include "../../Hook.h"

class RenderCtxHook : public Hook {
public:
    RenderCtxHook(Manager* mgr) : Hook(mgr) {
        //this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_RENDERCONTEXT_RENDERCONTEXTTICK */