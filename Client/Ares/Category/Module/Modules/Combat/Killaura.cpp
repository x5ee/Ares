#include "Killaura.h"

auto Killaura::onGameMode(GameMode* GM) -> void {

    if(std::chrono::system_clock::now() < (this->time + std::chrono::milliseconds(this->msDelay)))
        return;

    this->time = std::chrono::system_clock::now();

    auto player = GM->player;
    auto level = player->getLevel();
    auto myPos = *player->getPosition();
    auto localRuntimeID = player->getRuntimeID();
    auto entMap = this->category->mgr->entityMap;

    auto instance = MC::getClientInstance();
    auto screenName = instance->getTopScreenName();

    if(entMap.empty() || (screenName.rfind("hud_screen") != std::string::npos && this->category->mgr->isUsingKey(VK_SHIFT)))
        return;
    
    auto dists = std::map<uint64_t, double>();
    for(auto [ runtimeId, ent ] : entMap) {

        if(localRuntimeID == runtimeId || !ent->isAlive() || !ent->isAttackableMob())
            continue;
        
        auto typeId = ent->getEntityTypeId();
        
        if(typeId == 63 && !attackPlayers)
            continue;
        else if(typeId != 63 && !attackMobs)
            continue;
        
        auto dist = (*ent->getPosition()).dist(myPos);

        if(dist <= this->range)
            dists[runtimeId] = dist;

    };

    std::vector<std::pair<uint64_t, double>> distsVector(dists.begin(), dists.end());
    
    std::sort(distsVector.begin(), distsVector.end(),
        [&](const std::pair<uint64_t, double>& a, const std::pair<uint64_t, double>& b) {
            return a.second < b.second;
        }
    );

    if(sortByHealth) {

        const int maxElementsToKeep = 5;
        
        if (distsVector.size() > maxElementsToKeep)
            distsVector.resize(maxElementsToKeep);
        
        std::sort(distsVector.begin(), distsVector.end(),
            [&](const std::pair<uint64_t, double>& a, const std::pair<uint64_t, double>& b) {
                
                auto entA = level->getRuntimeEntity(a.first);
                auto entB = level->getRuntimeEntity(b.first);

                return entA->getMovementProxy()->getHealth() < entB->getMovementProxy()->getHealth();

            }
        );

    };

    dists = std::map<uint64_t, double>(distsVector.begin(), distsVector.end());

    if(dists.empty())
        return;
    
    auto count = 0;
    for(auto [ runtimeId, dist ] : dists) {

        auto entity = level->getRuntimeEntity(runtimeId);

        if(!entity || !entity->isAlive() || !entity->isAttackableMob())
            continue;
        
        if(count >= 4)
            break;
        
        count++;
        player->swing();
        GM->attack(entity);

    };

};

auto Killaura::onImGuiOptions(void) -> void {

    ImGui::SliderFloat("Range", &this->range, 1.f, 12.f);
    
    ImGui::Checkbox("Mobs", &this->attackMobs);
    ImGui::SameLine();
    ImGui::Checkbox("Players", &this->attackPlayers);
    ImGui::SameLine();
    ImGui::Checkbox("Sort By Health", &this->sortByHealth);

};