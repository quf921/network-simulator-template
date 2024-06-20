#ifndef SERVICE_INSTALLER_H
#define SERVICE_INSTALLER_H

#include "host.h"
#include "service.h"
#include "object.h"

// 서비스를 설치하는 역할
class ServiceInstaller : public Object {
private:
  virtual std::string name() override { return "ServiceInstaller"; }
protected:
  // 호스트와 서비스 사이의 관계를 설정한다.
  void install(Host *host, Service *service);
};

#endif