#ifndef CLIENT_CLIENT
#define CLIENT_CLIENT

#include "SDK/Minecraft.h"
#include "Utils/Utils.h"
#include "Mem/Mem.h"

class Manager;

class Client {
public:
    std::string name;
    Manager* mgr;
public:
    bool isRunning = false;
public:
    Client(std::string);
};

#endif /* CLIENT_CLIENT */