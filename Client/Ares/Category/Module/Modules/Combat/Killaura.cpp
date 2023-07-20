#include "Killaura.h"

auto Killaura::onGameMode(GameMode* GM) -> void {

    auto player = GM->player;
    auto level = player->getLevel();
    auto myPos = *player->getPosition();
    auto localRuntimeID = player->getRuntimeID();
    auto entMap = this->category->mgr->entityMap;

    if(entMap.empty())
        return;
    
    auto dists = std::map<uint64_t, double>();
    for(auto [ runtimeId, ent ] : entMap) {

        if(!ent->isAlive() || localRuntimeID == runtimeId || !player->canAttack(ent, false))
            continue;
        
        auto typeId = ent->getEntityTypeId();

        if(typeId == 64 || typeId == 69)
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

    dists = std::map<uint64_t, double>(distsVector.begin(), distsVector.end());
    
    auto count = 0;
    for(auto [ runtimeId, dist ] : dists) {

        auto entity = level->getRuntimeEntity(runtimeId);

        if(!entity || !player->canAttack(entity, false) || !entity->isAlive())
            continue;
        
        if(count >= 2)
            break;
        
        count++;
        player->swing();
        GM->attack(entity);

    };

};