#include "link.h"
#include "node.h"
#include <iostream>

void Link::send(Node *startNode, Packet *packet) {
    std::stringstream ss;
    Node *sendNode = other(startNode);
    ss << "Link: forwarding packet from node #" << startNode->id() << ", to node #" << sendNode->id();
    log(ss.str());
    sendNode->receive(packet);
    
}