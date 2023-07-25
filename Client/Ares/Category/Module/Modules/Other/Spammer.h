#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_SPAMMER
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_SPAMMER

#include "../../Module.h"

class Spammer : public Module {
public:
    Spammer(Category* c) : Module("Spammer", c) {
        //
    };
public:
    auto onRenderCtx(void*) -> void override;
private:
    std::string msg;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_SPAMMER */