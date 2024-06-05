#include "../echo_service.h"
#include "../echo_service_installer.h"
#include "../host.h"
#include "../link_installer.h"
#include "../manual_router.h"
#include "../message_service_installer.h"
#include <vector>

#include <iostream>

#define ECHO_PORT 3000

int main() {
  // ---------- //
  // 토폴로지 설정 //
  // ---------- //

  // 호스트를 생성한다
  std::cout << "create host" << std::endl;
  Host *echoServer = new Host(1);
  Host *messageClient = new Host(0);

  // 서비스를 설치한다
  std::cout << "install service" << std::endl;
  EchoServiceInstaller echoServiceInstaller(ECHO_PORT);
  echoServiceInstaller.install(echoServer);
  MessageServiceInstaller messageServiceInstaller(echoServer->address(),
                                                  ECHO_PORT);
  MessageService *messageService =
      messageServiceInstaller.install(messageClient);

  // 라우터를 생성한다.
  std::cout << "create router" << std::endl;
  std::vector<ManualRouter *> routers;
  for (int i = 0; i < 4; i++) {
    routers.push_back(new ManualRouter());
  }

  // 라우터와 호스트 간에 링크로 연결한다.
  std::cout << "connect link for router and host" << std::endl;
  LinkInstaller linkInstaller;
  std::vector<Link *> links;
  links.push_back(linkInstaller.install(routers[0], echoServer));    // 0
  links.push_back(linkInstaller.install(routers[0], routers[1]));    // 1
  links.push_back(linkInstaller.install(routers[0], routers[2]));    // 2
  links.push_back(linkInstaller.install(routers[1], routers[3]));    // 3
  links.push_back(linkInstaller.install(routers[2], routers[3]));    // 4
  links.push_back(linkInstaller.install(routers[3], messageClient)); // 5

  // 라우팅 테이블을 설정한다.
  std::cout << "setting routing table" << std::endl;
  routers[0]->addRoutingEntry(echoServer->address(), links[0]);
  routers[0]->addRoutingEntry(messageClient->address(), links[1]);
  routers[0]->addRoutingEntry(messageClient->address(), links[2]);

  routers[1]->addRoutingEntry(echoServer->address(), links[1]);
  routers[1]->addRoutingEntry(messageClient->address(), links[3]);

  routers[2]->addRoutingEntry(echoServer->address(), links[2]);
  routers[2]->addRoutingEntry(messageClient->address(), links[4]);

  routers[3]->addRoutingEntry(echoServer->address(), links[3]);
  routers[3]->addRoutingEntry(echoServer->address(), links[4]);
  routers[3]->addRoutingEntry(messageClient->address(), links[5]);

  // 토폴로지는 다음 그림과 같다:
  //
  //   echoServer
  //       |
  //     router0
  //      /   |
  // router1  router2
  //      \   |
  //     router3
  //       |
  //  messageClient

  // ------------ //
  // 시뮬레이션 수행 //
  // ------------ //

  // 각 호스트를 초기화한다.
  std::cout << "init host" << std::endl;

  echoServer->initialize();
  messageClient->initialize();

  // 메시지를 전송한다.
  std::cout << "send message" << std::endl;

  messageService->send("Hello, world!");
  messageService->send("Bye, world!");

  // --- //
  // 정리 //
  // --- //

  // 생성한 객체를 제거한다.
  std::cout << "delete" << std::endl;

  for (size_t i = 0; i < links.size(); i++) {
    delete links[i];
  }

  for (size_t i = 0; i < routers.size(); i++) {
    delete routers[i];
  }

  delete echoServer;
  delete messageClient;

  std::cout << "end programe" << std::endl;
}