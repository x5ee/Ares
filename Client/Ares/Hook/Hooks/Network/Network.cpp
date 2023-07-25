#include "Network.h"
#include "../../../Category/Module/Module.h"

typedef void (__thiscall* Send)(LoopbackPacketSender*, Packet*);
Send _Send;

Manager* pktMgr = nullptr;

auto SendCallback(LoopbackPacketSender* _this, Packet* packet) -> void {

    bool cancel = false;
    
    if(pktMgr) {

        for(auto category : pktMgr->categories) {

            for(auto module : category->modules) {

                if(module->isEnabled)
                    module->onPacket(packet, &cancel);

            };

        };

    };

    if(!cancel)
        _Send(_this, packet);

};

auto NetworkHook::init(void) -> void {

    pktMgr = this->mgr;
    
    auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 8B 5C 24 ? 48 89 06 33 C0");

    if(!sig)
        return Utils::debugOutput("Failed to find signature for LoopbackPacketSender VTable!");
    
    auto offset = *(int*)(sig + 3);
    auto VTable = (uintptr_t**)(sig + offset + 7);

    if(MH_CreateHook((void*)VTable[1], &SendCallback, reinterpret_cast<LPVOID*>(&_Send)) == MH_OK)
        MH_EnableHook((void*)VTable[1]);
    else
        Utils::debugOutput("Failed to create detour for LoopbackPacketSender::send");

};