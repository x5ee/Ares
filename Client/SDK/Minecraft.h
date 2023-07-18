#ifndef CLIENT_SDK_MINECRAFT
#define CLIENT_SDK_MINECRAFT

#include "Classes/ClientInstance.h"

enum MouseAction { NONE = 0, LMB = 1, RMB = 2, WHEEL_CLICK = 3, WHEEL_SCROLL = 4 };

class MC {
public:
    static auto getClientInstance(void) -> ClientInstance*;
};

#endif /* CLIENT_SDK_MINECRAFT */