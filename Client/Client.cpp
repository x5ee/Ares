#include "Client.h"
#include "Ares/Manager.h"

Client::Client(std::string n) {

    Utils::setDebugPath(n);
    
    this->name = n.c_str();
    this->mgr = new Manager(this);

};