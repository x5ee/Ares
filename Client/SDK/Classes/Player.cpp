#include "Player.h"

auto Player::getGameMode(void) -> GameMode* {

    return *(GameMode**)((uintptr_t)(this) + 0xE70);

};