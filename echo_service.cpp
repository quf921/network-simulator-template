#include "echo_service.h"

void EchoService::receive(Packet *packet) {
    std::cout << "EchoService: received \"" << packet->dataString() << 
    "\" from " << packet->destAddress().toString() <<":"<<packet->destPort() << 
    ", send reply with same data" << std::endl;
    
    Packet *newPacket = new Packet(
        packet->destAddress(), packet->srcAddress(),
        packet->destPort(), packet->srcPort(),
        packet->dataString()
    );

    host_->send(newPacket);
}