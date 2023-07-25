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
    auto onImGuiOptions(void) -> void override;
private:
    std::string msg;
public:
    std::chrono::time_point<std::chrono::system_clock> time = std::chrono::system_clock::now();
    int msDelay = 50;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_SPAMMER */