#include "ClickGui.h"

auto ClickGui::onImGui(void) -> void {

    auto categories = this->category->mgr->categories;
    
    static int selectedCategory = 0;
    static int selectedModule = 0;
    
    if(ImGui::Begin("ImGui", nullptr, ImGuiWindowFlags_MenuBar)) {

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
                
                if(ImGui::Button(module->name.c_str(), ImVec2(0, 0)))
                    module->isEnabled = !module->isEnabled;
                
                ImGui::EndChild();

            };

            ImGui::EndChild();

        };
        
        ImGui::End();

    };

};