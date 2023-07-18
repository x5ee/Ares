#ifndef CLIENT_ARES_HOOK_HOOK
#define CLIENT_ARES_HOOK_HOOK

class Hook {
public:
    virtual auto init(void) -> void {};
};

#endif /* CLIENT_ARES_HOOK_HOOK */