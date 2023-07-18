#include "TestModule.h"

auto TestModule::onImGui(void) -> void {

    if(ImGui::Begin("ImGui")) {

        ImGui::End();

    };

    static bool once = false;

    if(!once) {

        once = true;

        auto instance = MC::getClientInstance();
        auto player = (instance ? instance->getPlayer() : nullptr);
        
        std::ostringstream o;
        o << std::hex << player;

        Utils::debugOutput(o.str());

        auto size = player->getSize();
        auto sizeStr = std::string(std::to_string(size.x) + ", " + std::to_string(size.y));

        Utils::debugOutput(sizeStr);

    };

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    GM->player->setSprinting(true);

};