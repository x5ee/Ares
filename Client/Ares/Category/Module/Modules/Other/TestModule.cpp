#include "TestModule.h"

auto TestModule::onTick(void) -> void {

    //

};

auto TestModule::onEnable(void) -> void {

    auto instance = MC::getClientInstance();
    
    std::ostringstream o;
    o << std::hex << instance << std::endl;

    Utils::debugOutput(o.str());

};

auto TestModule::onDisable(void) -> void {

    //

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    //

};