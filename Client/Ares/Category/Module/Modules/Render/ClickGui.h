#ifndef CLIENT_ARES_CATEGORY_MODULE_MODULES_RENDER_CLICKGUI
#define CLIENT_ARES_CATEGORY_MODULE_MODULES_RENDER_CLICKGUI

#include "../../Module.h"

class ClickGui : public Module {
public:
    ClickGui(Category* c) : Module("ClickGui", c) {
        this->isEnabled = true;
    };
public:
    auto onImGui(void) -> void override;
};

#endif /* CLIENT_ARES_CATEGORY_MODULE_MODULES_RENDER_CLICKGUI */