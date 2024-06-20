#include "router.h"
#include <iostream>

void Router::receive(Packet *packet) {
    std::stringstream ss;

    std::string status = "no route for packet";
    RoutingEntry routingEntry = routingTable_.front();
    for (int i = 0; i < (int)routingTable_.size(); i++) {
        // std::cout << "[test] print router receive address: " << routingTable_[i].destination.toString() << 
        // " : "<< packet->destAddress().toString() << " : " << (routingTable_[i].destination == packet->destAddress()) << std::endl;
        if (routingTable_[i].destination == packet->destAddress()) {
            routingEntry = routingTable_[i];
            status = "forwarding packet: ";
            break;
        }
    }

    ss << status << packet->toString() << " to " << routingEntry.nextLink->toString();
    
    log(ss.str());

    if (status == "forwarding packet: ") {
        routingEntry.nextLink->send(this, packet);
    }
}