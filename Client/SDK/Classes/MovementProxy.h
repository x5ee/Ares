#ifndef CLIENT_SDK_CLASSES_MOVEMENTPROXY
#define CLIENT_SDK_CLASSES_MOVEMENTPROXY

#include "../../Utils/Utils.h"

class MovementProxy {
public:
    uintptr_t** VTable;
public:
    auto isOnGround(void) -> bool;
    auto setOnGround(bool) -> void;
public:
    auto getHealth(void) -> int;
};

#endif /* CLIENT_SDK_CLASSES_MOVEMENTPROXY */