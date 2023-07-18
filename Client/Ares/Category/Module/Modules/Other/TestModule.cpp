#include "TestModule.h"

auto TestModule::onGameMode(GameMode* GM) -> void {

    GM->player->setSprinting(true);

};