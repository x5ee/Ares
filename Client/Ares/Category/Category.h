#ifndef CLIENT_ARES_CATEGORY_CATEGORY
#define CLIENT_ARES_CATEGORY_CATEGORY

#include "../Manager.h"

class Category {
public:
    std::string name;
    Manager* mgr = nullptr;
public:
    std::vector<class Module*> modules;
public:
    Category(Manager*, std::string);
public:
    auto baseTick(void) -> void;
public:
    auto registerModule(class Module*) -> void;
};

#endif /* CLIENT_ARES_CATEGORY_CATEGORY */