#ifndef CLIENT_SDK_CLASSES_PACKET
#define CLIENT_SDK_CLASSES_PACKET

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class Packet {
public:
    uintptr_t** VTable;
private:
    char pad[0x24];
public:
    template<typename T>
    auto setVTable(uintptr_t) -> void;
public:
    auto getName(void) -> std::string;
};

enum class TextPacketType { RAW = 0, CHAT = 1, TRANSLATION = 2, POPUP = 3, JUKEBOX_POPUP = 4, TIP = 5, SYSTEM = 6, WHISPER = 7, ANNOUNCEMENT = 8, JSON_WHISPER = 9, JSON = 10, JSON_ANNOUNCEMENT = 11 };

class TextPacket : public Packet {
public:
    TextPacket(void);
    TextPacket(class Player*, std::string);
public:
    TextPacketType type;
public:
    std::string author;
    std::string message;
private:
    unsigned char paddd[24];
public:
    bool translationNeeded = false;
private:
    unsigned char padddd[7];
public:
    std::string xboxUserId;
    std::string platformChatId;
};

#endif /* CLIENT_SDK_CLASSES_PACKET */