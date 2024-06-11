#ifndef LINK_INSTALLER_H
#define LINK_INSTALLER_H

#include "link.h"
#include "service.h"

class Object;

class LinkInstaller : public Object {
private:
  std::string name() override { return "LinkInstaller"; }
public:
  // 노드 a, b 사이에 링크를 설치하고 반환한다.
  Link *install(Node *a, Node *b, double delay);
  Link *install(Node *a, Node *b);
};

#endif