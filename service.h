#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"
#include "object.h"

class Host;

class Service : public Object {
  friend class ServiceInstaller;

protected:
  // 서비스가 설치된 호스트
  Host *host_;

  // 서비스가 사용하는 포트
  short port_;

  Service(Host *host, int port) : host_(host), port_(port) {}

public:
  short getPort() { return port_; }
  void setPort(short port) { port_ = port; }
  virtual void receive(Packet *packet) = 0;
  virtual void send() = 0;

  std::string name() override { return "Service"; }
};

#endif