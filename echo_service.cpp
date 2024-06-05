#include "echo_service.h"

void EchoService::receive(Packet *packet) {
    std::cout << "EchoService: received " << packet->dataString() << 
    "from" << packet->destAddress().toString() <<":"<<packet->destPort() << 
    ", send reply with same data" << std::endl;

    host_->send(packet);
}