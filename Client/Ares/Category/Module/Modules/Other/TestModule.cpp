#include "TestModule.h"

auto TestModule::onTick(void) -> void {

    //

};

auto TestModule::onEnable(void) -> void {

    auto instance = MC::getClientInstance();
    auto player = (instance ? instance->getPlayer() : nullptr);

    std::ostringstream o;
    o << std::hex << player;

    Utils::debugOutput(std::string("Player: " + o.str()));

};

auto TestModule::onDisable(void) -> void {

    //

};