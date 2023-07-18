#include "TestModule.h"

auto TestModule::onImGui(void) -> void {

    auto categories = this->category->mgr->categories;
    
    if(ImGui::Begin("ImGui")) {

        for(auto category : categories) {

            //

        };
        
        ImGui::End();

    };

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    GM->player->setSprinting(true);

};