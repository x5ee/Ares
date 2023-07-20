#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_TESTMODULE
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_TESTMODULE

#include "../../Module.h"

class TestModule : public Module {
public:
    TestModule(Category* c) : Module("Test Module", c) {
        //this->isEnabled = true;
    };
public:
    auto onTick(void) -> void override;
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_OTHER_TESTMODULE */