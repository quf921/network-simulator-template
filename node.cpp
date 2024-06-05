#include "node.h"
#include <iostream>

int Node::nextId_ = 0;

// void Node::receive(Packet *packet) {
//     std::cout << "resive packet" << packet->dataString() << std::endl;
//     // TODO: router에게 패킷을 받았다고 인식시키기, virtual 사용하기
// }