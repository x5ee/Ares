#ifndef CLIENT_ARES_CATEGORY_CATEGORY
#define CLIENT_ARES_CATEGORY_CATEGORY

#include "../Manager.h"

class Category {
public:
    std::string name;
    Manager* mgr = nullptr;
public:
    Category(Manager*, std::string);
};

#endif /* CLIENT_ARES_CATEGORY_CATEGORY */