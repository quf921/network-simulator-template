#include "link.h"
#include "node.h"
#include <iostream>

void Link::send(Node *startNode, Packet *packet) {
    Node *sendNode = other(startNode);
    std::cout << "Link: forwarding packet from node #" << startNode->id() << ", to node #" << sendNode->id() << std::endl;
    sendNode->receive(packet);
    
}
