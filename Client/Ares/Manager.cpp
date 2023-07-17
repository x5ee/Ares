#include "Manager.h"

Manager::Manager(Client* c) {

    this->client = reinterpret_cast<Client*>(c);

};