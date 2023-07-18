#ifndef CLIENT_SDK_CLASSES_LEVEL
#define CLIENT_SDK_CLASSES_LEVEL

#include "../../Utils/Utils.h"

class Level {
public:
    uintptr_t** VTable;
public:
    auto getRuntimeEntity(uint64_t runtimeId, bool p2 = false) -> class Actor*;
};

#endif /* CLIENT_SDK_CLASSES_LEVEL */