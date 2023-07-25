#include "TestModule.h"

auto TestModule::onTick(void) -> void {

    //

};

auto TestModule::onEnable(void) -> void {

    auto instance = MC::getClientInstance();
    auto player = (instance ? instance->getPlayer() : nullptr);
    
    auto proxy = player->getMovementProxy();

    std::ostringstream o;
    o << std::hex << proxy->VTable[74];

    Utils::debugOutput(o.str());

};

auto TestModule::onDisable(void) -> void {

    //

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    //

};