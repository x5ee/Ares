#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULE
#define CLIENT_ARES_CATEGORY_MODULE_MODULE

#include "../Category.h"

class Module {
public:
    std::string name;
    Category* category;
public:
    bool wasEnabled = false, isEnabled = false;
public:
    Module(std::string, Category*);
public:
    auto baseTick(void) -> void;
public:
    virtual auto onTick(void) -> void {};
    virtual auto onEnable(void) -> void {};
    virtual auto onDisable(void) -> void {};
public:
    virtual auto onGameMode(GameMode*) -> void {};
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULE */