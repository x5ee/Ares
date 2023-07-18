#include "Manager.h"
#include "Category/Category.h"

Manager::Manager(Client* c) {

    this->client = reinterpret_cast<Client*>(c);

    this->initHooks();
    this->initCategories();

};

auto Manager::initSubModules(void) -> void {

    //

};

auto Manager::initCategories(void) -> void {

    this->categories.erase(this->categories.begin(), this->categories.end());
    
    for(const auto& name : { "Combat", "Move", "Player", "Misc", "World", "Other" })
        this->categories.push_back(new Category(this, name));

};

#include "Hook/Hooks/EntityTick/EntityLevelTick.h"
#include "Hook/Hooks/GameMode/GameMode.h"

auto Manager::initHooks(void) -> void {

    this->hooks.erase(this->hooks.begin(), this->hooks.end());

    if(MH_Initialize() != MH_OK)
        return;
    
    this->hooks.push_back(new EntityLevelTickHook(this));
    this->hooks.push_back(new GameModeHook(this));

};