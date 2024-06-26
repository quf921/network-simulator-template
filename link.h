#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include <cstdlib>
#include "object.h"

class Node;

class Link : public Object{
  friend class LinkInstaller;

private:
  Link(Node *nodeA, Node *nodeB, double delay) : nodeA_(nodeA), nodeB_(nodeB), delay_(delay) {}
  Node *nodeA_;
  Node *nodeB_;
  double delay_;
  
  // 매개변수로 주어진 노드가 아닌 반대편 노드를 구한다.
  Node *other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
  }

  virtual std::string name() override { return "Link"; }
public:
  // packet을 nodeA에서 nodeB로 전달한다
  void send(Node *startNode, Packet *packet);

  Node *nodeA() const { return nodeA_; }
  Node *nodeB() const { return nodeB_; }
  int delay() const { return delay_; }
};

#endif