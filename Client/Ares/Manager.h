#ifndef CLIENT_ARES_MANAGER
#define CLIENT_ARES_MANAGER

#include "../Client.h"

class Manager {
public:
    Client* client = nullptr;
public:
    Manager(Client*);
};

#endif /* CLIENT_ARES_MANAGER */