#include "echo_service.h"

void EchoService::receive(Packet *packet) {
    std::stringstream ss;

    ss << "EchoService: received \"" << packet->dataString() << 
    "\" from " << packet->srcAddress().toString() <<":"<<packet->srcPort() << 
    ", send reply with same data";
    log(ss.str());
    
    Packet *newPacket = new Packet(
        packet->destAddress(), packet->srcAddress(),
        packet->destPort(), packet->srcPort(),
        packet->dataString()
    );

    delete packet;
    
    host_->send(newPacket);
}