#include "TestModule.h"

auto TestModule::onImGui(void) -> void {

    if(ImGui::Begin("ImGui")) {

        ImGui::End();

    };

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    GM->player->setSprinting(true);

};