#include "Hitbox.h"

auto Hitbox::onGameMode(GameMode* GM) -> void {

    auto player = GM->player;
    auto localRuntimeID = player->getRuntimeID();
    auto entMap = this->category->mgr->entityMap;

    for(auto [ runtimeId, entity ] : entMap) {

        if(runtimeId == localRuntimeID)
            continue;
        
        auto typeId = entity->getEntityTypeId();

        if(!this->collisions.contains(typeId))
            this->collisions[typeId] = entity->getSize();
        
        entity->setSize(this->radius.x, this->radius.y);

    };

};

auto Hitbox::onDisable(void) -> void {

    for(auto [ runtimeId, entity ] : this->category->mgr->entityMap) {

        auto typeId = entity->getEntityTypeId();

        if(this->collisions.contains(typeId))
            this->collisions[typeId] = entity->getSize();
        
        auto size = this->collisions[typeId];
        entity->setSize(size.x, size.y);

    };

    this->collisions.clear();

};

auto Hitbox::onImGuiOptions(void) -> void {

    ImGui::SliderFloat("Width", &this->radius.x, 0.f, 12.f);
    ImGui::SliderFloat("Height", &this->radius.y, 0.f, 12.f);

};