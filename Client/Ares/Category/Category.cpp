#include "Category.h"
#include "Module/Module.h"

Category::Category(Manager* m, std::string n) {

    this->mgr = reinterpret_cast<Manager*>(m);
    this->name = n.c_str();

};

auto Category::baseTick(void) -> void {

    for(auto module : this->modules)
        module->baseTick();

};

auto Category::registerModule(Module* module) -> void {

    if(std::find(this->modules.begin(), this->modules.end(), module) == this->modules.end())
        this->modules.push_back(module);

};