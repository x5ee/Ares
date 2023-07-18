#include "Category.h"

Category::Category(Manager* m, std::string n) {

    this->mgr = reinterpret_cast<Manager*>(m);
    this->name = n.c_str();

};