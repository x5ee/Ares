#include "ClickGui.h"

auto ClickGui::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    *cancel = true;

    if(isDown && key == VK_ESCAPE)
        this->isEnabled = false;

};

auto ClickGui::onMouse(MouseAction action, bool isDown, Vec2<short> mousePos, bool* cancel) -> void {

    if(action == MouseAction::NONE || !isDown)
        return;
    
    *cancel = true;

};

auto ClickGui::onImGui(void) -> void {

    ImGuiStyle& style = ImGui::GetStyle();
    
    style.WindowRounding = 10.0f; // Adjust the window rounding to your preference
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.8f); // Light gray window background
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f); // Dark gray title bar background
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f); // Dark gray title bar background when active (hovered)

    // Change button colors
    style.Colors[ImGuiCol_Button] = ImVec4(0.3f, 0.5f, 0.8f, 1.0f);       // Button background color when idle
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.4f, 0.6f, 0.9f, 1.0f);  // Button background color when hovered
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.2f, 0.4f, 0.7f, 1.0f);   // Button background color when pressed

    // Change button rounding
    style.FrameRounding = 6.0f;

    // Change button border size and rounding (optional)
    style.GrabMinSize = 40.0f; // Minimum size for "drag box" in a button
    style.GrabRounding = 4.0f; // Rounding for "drag box" in a button

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(8.0f, 6.0f)); // Adjust frame padding for all elements
    //ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]); // Use a larger font for improved readability

    auto categories = this->category->mgr->categories;
    
    static int selectedCategory = 0;
    static int selectedModule = 0;

    const float contentWidth = 400.0f;
    const float windowWidth = 150.0f + 200.0f + contentWidth + 16.0f;
    
    if(ImGui::Begin(this->category->mgr->client->name.c_str(), nullptr, ImGuiWindowFlags_MenuBar)) {
        
        static bool setWindowSize = false;

        if(!setWindowSize) {
            setWindowSize = true;
            ImGui::SetWindowSize(ImVec2(windowWidth, 600.0f));
        };

        if(ImGui::BeginChild("Categories", ImVec2(150, 0), true)) {

            for (int i = 0; i < categories.size(); i++) {

                if (ImGui::Selectable(categories[i]->name.c_str(), selectedCategory == i)) {
                    
                    if(selectedCategory != i)
                        selectedModule = 0;

                    selectedCategory = i;

                };

            };

            ImGui::EndChild();

        }

        ImGui::SameLine();

        if(ImGui::BeginChild("Modules", ImVec2(200, 0), true)) {

            auto category = categories.at(selectedCategory);
            auto modules = category->modules;

            for(int i = 0; i < modules.size(); i++) {

                if(ImGui::Selectable(modules.at(i)->name.c_str(), selectedModule == i)) {

                    selectedModule = i;

                };

            };
            
            ImGui::EndChild();

        };

        ImGui::SameLine();

        if(ImGui::BeginChild("Content", ImVec2(0, 0), true)) {

            auto modules = categories.at(selectedCategory)->modules;
            auto module = (modules.empty() ? nullptr : modules.at(selectedModule));

            if(module) {

                ImGui::Text(module->name.c_str());

                ImGui::PushStyleColor(ImGuiCol_Button, module->isEnabled ? ImVec4(0.0f, 1.0f, 0.0f, 1.0f) : ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
                
                if(ImGui::Button(module->name.c_str(), ImVec2(0.f, 0.f)))
                    module->isEnabled = !module->isEnabled;
                
                ImGui::PopStyleColor();

                module->onImGuiOptions();
                
                //ImGui::EndChild();

            };

            ImGui::EndChild();

        };
        
        ImGui::End();

    };

    ImGui::PopStyleVar();
    //ImGui::PopFont();

};

auto ClickGui::onRenderCtx(void* ctx) -> void {

    auto instance = MC::getClientInstance();
    auto screenName = (instance ? instance->getTopScreenName() : "");

    if(screenName.rfind("hud_screen") == std::string::npos)
        this->isEnabled = false;
    
    if(instance)
        instance->releaseMouse();

};

auto ClickGui::onDisable(void) -> void {

    Sleep(100);

    auto instance = MC::getClientInstance();

    if(!instance)
        return;
    
    auto screenName = instance->getTopScreenName();

    if(screenName.rfind("hud_screen") != std::string::npos)
        instance->grabMouse();

};