#include "Manager.h"
#include "Category/Category.h"

Manager::Manager(Client* c) {

    this->client = reinterpret_cast<Client*>(c);

    if(MH_Initialize() == MH_OK)
        this->initHooks();
    
    this->initCategories();

};

auto Manager::initCategories(void) -> void {

    this->categories.erase(this->categories.begin(), this->categories.end());
    
    for(const auto& name : { "Combat", "Move", "Player", "Misc", "World", "Other" })
        this->categories.push_back(new Category(this, name));

};

auto Manager::initHooks(void) -> void {

    this->hooks.erase(this->hooks.begin(), this->hooks.end());

};