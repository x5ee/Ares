#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "Player.h"

class ClientInstance {
public:
    unsigned long long** VTable;
public:
    auto getPlayer(void) -> Player*;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */