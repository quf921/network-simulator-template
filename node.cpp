#include "node.h"
#include <iostream>

int Node::nextId_ = 0;

std::string Node::name() {
    return "Node";
}