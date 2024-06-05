#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Node {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;

protected:
  std::vector<Link *> links;
  
public:
  virtual void receive(Packet *packet) = 0;

  Node() : id_(nextId_++) {}
  int id() const { return id_; }

  virtual ~Node() { }
};

#endif