#include "Hook.h"

Hook::Hook(Manager* m) {

    this->mgr = reinterpret_cast<Manager*>(m);

};