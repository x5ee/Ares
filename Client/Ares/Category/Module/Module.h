#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULE
#define CLIENT_ARES_CATEGORY_MODULE_MODULE

#include "../Category.h"

class Module {
public:
    std::string name;
    Category* category;
public:
    bool wasEnabled = false, isEnabled = false;
    uint64_t key = 0x0;
public:
    Module(std::string, Category*);
public:
    auto baseTick(void) -> void;
public:
    virtual auto onTick(void) -> void {};
    virtual auto onEnable(void) -> void {};
    virtual auto onDisable(void) -> void {};
public:
    virtual auto onImGui(void) -> void {};
    virtual auto onImGuiOptions(void) -> void {};
public:
    virtual auto onGameMode(GameMode*) -> void {};
public:
    virtual auto onKey(uint64_t, bool, bool*) -> void {};
    virtual auto onMouse(MouseAction, bool isDown, Vec2<short>, bool*) -> void {};
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULE */