#include "message_service.h"

void MessageService::send(std::string message) {
    Packet *packet = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(packet);
}

void MessageService::receive(Packet *packet) {
    std::stringstream ss;
    ss << "received \"" << packet->dataString() << 
    "\" from " << packet->srcAddress().toString() <<":"<<packet->srcPort();
    
    log(ss.str());
    delete packet;
}
