#include "host.h"
#include <iostream>

void Host::initialize() {
    for (int i = 0; i < services_.size(); i++) {
        // std::cout << "[test] init get port: " << services_.front()->getPort() << std::endl;
        if (services_.front()->getPort() == -1) {  // message service defualt port
            services_[i]->setPort(i+1000);
        }
        services_table_[services_[i]] = services_[i]->getPort();
    }
}

void Host::send(Packet *packet) {
    std::cout << "Host #" << id() << 
    ": sending packet (from: " << packet->srcAddress().toString() << 
    ", to: " << packet->destAddress().toString() << 
    ", " << packet->dataString().length() << 
    " bytes)" << std::endl;
    
    Link *link = links[0];
    link->send(this, packet);
}

void Host::receive(Packet *packet) {
    for (const auto& service: services_table_) {
        if (service.second == packet->destPort()) {
            std::cout << "Host #" << id() << ": received packet, destination port:" << packet->destPort() << std::endl;
            service.first->receive(packet);
            return;
        }
    }
    std::cout << "Host #" << id() << 
    ": no service for packet (from: " << packet->srcAddress().toString() << 
    ", to: " << packet->destAddress().toString() << 
    ", " << packet->dataString().length() << 
    " bytes)" << std::endl;
}
