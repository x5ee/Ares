#include "Spammer.h"

auto Spammer::onRenderCtx(void* ctx) -> void {

    auto instance = *(ClientInstance**)((uintptr_t)(ctx) + 0x8);
    auto lp = (instance ? instance->getLoopbackPacketSender() : nullptr);

    auto player = (instance ? instance->getPlayer() : nullptr);

    if(!player)
        return;
    
    auto rndNum = [&](int min, int max) {

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);

    };

    if(msg.length() <= 0)
        msg = std::string(this->category->mgr->client->name + " Client, Discord Code: PbBM2tCPun");
    
    auto chatMsg = std::string("[ " + std::to_string(rndNum(0, 100)) + " ] " + msg + " [ " + std::to_string(rndNum(0, 100)) +" ]");
    
    auto pkt = TextPacket(player, chatMsg);
    lp->send(&pkt);

};