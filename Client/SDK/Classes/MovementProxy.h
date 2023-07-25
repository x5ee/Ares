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
    auto setCollision(bool) -> void;
public:
    auto setRotation(Vec2<float>*) -> void;
};

#endif /* CLIENT_SDK_CLASSES_MOVEMENTPROXY */