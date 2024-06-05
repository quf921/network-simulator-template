#include "host.h"
#include <iostream>

void Host::initialize() {
    for (int i = 0; i < 1; i++) {
        services_.front()->setPort(i);
        services_[i]->setPort(i);
        services_table_[services_[i]] = services_[i]->getPort();
    }
    std::cout << services_table_[0] << std::endl;
}

void Host::send(Packet *packet) {
    std::cout << 
    "Host #" << id() << 
    ": sending packet (from: " << packet->srcAddress().toString() << 
    ", to: " << packet->destAddress().toString() << 
    ", " << packet->dataString().length() << 
    " bytes)" << std::endl;
    std::cout << "this node id: " << this->id() << std::endl;
    Link *link = links[0];
    link->send(this, packet);
}

void Host::receive(Packet *packet) {
    std::cout<<"resive test" << services_[1] << std::endl;
    for (const auto& service: services_table_) {
        if (service.second == packet->destPort()) {
            std::cout << "resive data" << packet->dataString() << std::endl;
        }
    }
}
