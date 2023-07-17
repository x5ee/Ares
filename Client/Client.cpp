#include "Client.h"

Client::Client(std::string n) {

    Utils::setDebugPath(n);
    this->name = n.c_str();

};