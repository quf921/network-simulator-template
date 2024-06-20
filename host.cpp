#include "host.h"
#include <iostream>

void Host::initialize() {
    for (int i = 0; i < (int)services_.size(); i++) {
        if (services_[i]->getPort() == -1) {  // message service defualt port
            services_[i]->setPort(i+1000);
        }
        services_table_[services_[i]] = services_[i]->getPort();
    }
    
    // bulk service start

    for (int i = 0; i < (int)services_.size(); i++) {
        if (services_[i]->name() == "BulkSendService") {
            services_[i]->send();
        }
    }
}

void Host::send(Packet *packet) {
    std::stringstream ss;
    ss << "sending packet: " << packet->toString();
    log(ss.str());
    
    Link *link = links[0];

    link->send(this, packet);
}

void Host::receive(Packet *packet) {
    std::stringstream ss;
    for (const auto& service: services_table_) {
        if (service.second == packet->destPort()) {
            ss << "received packet: " << packet->toString() << " forwarding to " << service.first->toString();
            log(ss.str());
            service.first->receive(packet);
            return;
        }
    }
    ss << "Host #" << id() << 
    ": no service for packet (from: " << packet->srcAddress().toString() << 
    ", to: " << packet->destAddress().toString() << 
    ", " << packet->dataString().length() << 
    " bytes)";
    log(ss.str());
}
