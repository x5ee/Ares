#ifndef CLIENT_SDK_MINECRAFT
#define CLIENT_SDK_MINECRAFT

#include "Classes/ClientInstance.h"

class MC {
public:
    static auto getClientInstance(void) -> ClientInstance*;
};

#endif /* CLIENT_SDK_MINECRAFT */