#ifndef CLIENT_SDK_CLASSES_PACKET
#define CLIENT_SDK_CLASSES_PACKET

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class Packet {
public:
    uintptr_t** VTable;
public:
    template<typename T>
    auto setVTable(uintptr_t) -> void;
public:
    auto getName(void) -> std::string;
};

class TextPacket : public Packet {
public:
    TextPacket(void);
};

#endif /* CLIENT_SDK_CLASSES_PACKET */