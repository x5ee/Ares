#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "LoopbackPacketSender.h"
#include "Player.h"

class ClientInstance {
public:
    unsigned long long** VTable;
public:
    auto getLoopbackPacketSender(void) -> LoopbackPacketSender*;
public:
    auto getPlayer(void) -> Player*;
public:
    auto getbadrefdef(void) -> glmatrixf*;
public:
    auto grabMouse(void) -> void;
    auto releaseMouse(void) -> void;
    auto refocusMouse(void) -> void;
public:
    auto getTopScreenName(void) -> std::string;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */