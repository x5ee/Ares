#include "AutoSprint.h"

auto AutoSprint::onGameMode(GameMode* GM) -> void {

    GM->player->setSprinting(true);

};