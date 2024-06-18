#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>
#include "object.h"

class Node : public Object {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;

  virtual std::string name() override { return "Node"; }
protected:
  std::vector<Link *> links;
  
public:
  virtual void receive(Packet *packet) = 0;

  Node() : id_(nextId_++) {}
  int id() const { return id_; }

  virtual ~Node() {}
};

#endif