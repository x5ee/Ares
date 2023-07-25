#ifndef CLIENT_SDK_CLASSES_LOOPBACKPACKETSENDER
#define CLIENT_SDK_CLASSES_LOOPBACKPACKETSENDER

#include "Packet.h"

class LoopbackPacketSender {
private:
    virtual ~LoopbackPacketSender(void);
public:
    virtual auto send(Packet*) -> void;
};

#endif /* CLIENT_SDK_CLASSES_LOOPBACKPACKETSENDER */