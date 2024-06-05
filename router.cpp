#include "router.h"
#include <iostream>

void Router::receive(Packet *packet) {
    RoutingEntry routingEntry = routingTable_.front();
    routingEntry.nextLink->send(this, packet);

    std::cout << 
    "Router #" << id() << 
    ": sending packet (from: " << packet->srcAddress().toString() << 
    ", to: " << packet->destAddress().toString() << 
    ", " << packet->dataString().length() << 
    " bytes)" << std::endl;
}