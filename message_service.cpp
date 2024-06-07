#include "message_service.h"

void MessageService::send(std::string message) {
    Packet *packet = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(packet);
}

void MessageService::receive(Packet *packet) {
    std::cout << "MessageService: received \"" << packet->dataString() << 
    "\" from " << packet->destAddress().toString() <<":"<<packet->destPort() << std::endl;
}
