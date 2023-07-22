#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_RENDER_CLICKGUI
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_RENDER_CLICKGUI

#include "../../Module.h"

class ClickGui : public Module {
public:
    ClickGui(Category* c) : Module("ClickGui", c) {
        this->isEnabled = true;
        this->key = VK_TAB;
    };
public:
    auto onGameMode(GameMode*) -> void override;
    auto onKey(uint64_t, bool, bool*) -> void override;
    auto onMouse(MouseAction, bool, Vec2<short>, bool*) -> void override;
public:
    auto onImGui(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_RENDER_CLICKGUI */