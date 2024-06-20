#include "link.h"
#include "node.h"
#include <iostream>

void Link::send(Node *startNode, Packet *packet) {
    std::stringstream ss;
    Node *sendNode = other(startNode);
    ss << "packet in: " << packet->toString() << " from " << startNode->toString();
    log(ss.str());
    ss.clear();
    ss.str("");
    ss << "packet out: " << packet->toString() << " to " << sendNode->toString();
    log(ss.str());
    sendNode->receive(packet);
}