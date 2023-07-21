#include "Manager.h"
#include "Category/Category.h"

Manager::Manager(Client* c) {

    this->client = reinterpret_cast<Client*>(c);

    this->initHooks();
    this->initCategories();
    this->initSubModules();

};

auto Manager::baseTick(void) -> void {

    for(auto category : this->categories)
        category->baseTick();

};

#include "Category/Module/Modules/Combat/Killaura.h"
#include "Category/Module/Modules/Combat/Hitbox.h"

#include "Category/Module/Modules/Player/AutoSprint.h"

#include "Category/Module/Modules/Render/ClickGui.h"

#include "Category/Module/Modules/Other/TestModule.h"

auto Manager::initSubModules(void) -> void {

    auto combat = this->findCategory("Combat");

    if(combat) {

        new Killaura(combat);
        new Hitbox(combat);

    };

    auto player = this->findCategory("Player");

    if(player) {

        new AutoSprint(player);

    };

    auto render = this->findCategory("Render");

    if(render) {

        new ClickGui(render);

    };

    auto other = this->findCategory("Other");

    if(other) {

        new TestModule(other);

    };

};

auto Manager::initCategories(void) -> void {

    this->categories.erase(this->categories.begin(), this->categories.end());
    
    for(const auto& name : { "Combat", "Move", "Player", "Render", "World", "Other" })
        this->categories.push_back(new Category(this, name));

};

#include "Hook/Hooks/RenderContext/RenderContextTick.h"
#include "Hook/Hooks/EntityTick/EntityLevelTick.h"
#include "Hook/Hooks/SwapChain/SwapChain.h"
#include "Hook/Hooks/GameMode/GameMode.h"
#include "Hook/Hooks/Mouse/Mouse.h"
#include "Hook/Hooks/Key/Key.h"

auto Manager::initHooks(void) -> void {

    this->hooks.erase(this->hooks.begin(), this->hooks.end());

    if(MH_Initialize() != MH_OK)
        return;
    
    this->hooks.push_back(new SwapChainHook(this));
    this->hooks.push_back(new RenderCtxHook(this));
    
    this->hooks.push_back(new EntityLevelTickHook(this));
    this->hooks.push_back(new GameModeHook(this));
    this->hooks.push_back(new MouseHook(this));
    this->hooks.push_back(new KeyHook(this));

    for(auto hook : this->hooks) {

        hook->init();
        Sleep(500);

    };

};

auto Manager::findCategory(std::string name) -> Category* {

    auto categoryIterator = std::find_if(categories.begin(), categories.end(),
        [&name](const Category* category) {
            return category->name == name;
        }
    );

    if(categoryIterator != categories.end())
        return *categoryIterator;
    
    return nullptr;

};