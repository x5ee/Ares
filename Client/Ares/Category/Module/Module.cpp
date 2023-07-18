#include "Module.h"

Module::Module(std::string n, Category* c) {

    this->name = n.c_str();
    this->category = reinterpret_cast<Category*>(c);

    c->registerModule(this);

};

auto Module::baseTick(void) -> void {

    if(wasEnabled != isEnabled) {

        wasEnabled = isEnabled;

        if(isEnabled)
            onEnable();
        else
            onDisable();

    };

    if(isEnabled)
        onTick();

};