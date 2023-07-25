#include "Packet.h"
#include "Player.h"

template<typename T>
auto Packet::setVTable(uintptr_t sig) -> void {

    if(sig == NULL)
        return;
    
    auto offset = *(int*)(sig + 3);
    this->VTable = (uintptr_t**)(sig + offset + 7);

};

auto Packet::getName(void) -> std::string {

    using GetName = const char* (__fastcall*)(Packet*);
    auto _GetName = (GetName)(this->VTable[1]);

    return std::string(_GetName(this));

};

TextPacket::TextPacket(void) {

    static auto sig = Mem::findSig("48 8D 05 ? ? ? ? 48 89 45 ? C6 85 ? ? ? ? ? 48 89 B5");
    this->setVTable<TextPacket>(sig);

};

TextPacket::TextPacket(Player* player, std::string msg) {

    *this = TextPacket();

    this->type = TextPacketType::CHAT;
    this->author = player->getNameTag();
    this->message = msg;

    this->xboxUserId = std::string("");
    this->platformChatId = std::string("");

};