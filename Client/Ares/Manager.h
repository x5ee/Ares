#ifndef CLIENT_ARES_MANAGER
#define CLIENT_ARES_MANAGER

#include "../Client.h"

class Manager {
public:
    Client* client = nullptr;
public:
    std::map<uint64_t, Actor*> entityMap;
    std::map<uint64_t, bool> keyMap;
public:
    Manager(Client*);
public:
    std::vector<class Category*> categories;
    std::vector<class Hook*> hooks;
public:
    auto baseTick(void) -> void;
public:
    auto initSubModules(void) -> void;
    auto initCategories(void) -> void;
    auto initHooks(void) -> void;
public:
    auto findCategory(std::string) -> Category*;
    auto isUsingKey(uint64_t) -> bool;
};

#endif /* CLIENT_ARES_MANAGER */