#ifndef AUTO_ROUTER_H
#define AUTO_ROUTER_H

#include "host.h"
#include "link.h"
#include "router.h"
#include "service.h"
#include <algorithm>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <vector>

class AutoRouter : public Router {
private:
  virtual std::string name() override { return "AutoRouter"; }
public:
  void calculate(const std::vector<Node *> &nodes,
                 const std::vector<Link *> &links) {
    // 전체 노드와 링크 정보를 통해
    // 모든 호스트로 전달될 수 있는 라우팅 테이블을 구성한다
    // TODO: 구현
    // 다익스트라 : 각 노드 a, b, c, d, e 거리 계산 
    // a노드에서 다른 노드들로 가는 최소 거리 계산
    // a <- link a(delay: 거리정보) -> b ... 와 같이 연결되어 있다.
    // 인접행렬을 통해 구한다

    
    // 인접행렬 생성
    // double metrix[10000][10000];

    // for (int i = 0; i < nodes.size(); i++) {
    //   for (int j = 0; j < nodes.size(); j++) {
    //     Node* a = nodes[i];
    //     Node* b = nodes[j];

    //     // 노드 사이의 거리 구하기
    //     metrix[i][j] = -1;
    //     for (int k = 0; k < links.size(); k++) {
    //       Link* link = links[k];
    //       if (link->nodeA() == a && link->nodeB() == b) {
    //         metrix[i][j] = link->delay();
    //       }
    //     }
    //   }
    // }

    // // 결과 구한 다익스트라 메트릭스에서 호스트에 대한 최단 경로 추적하기(다음 홉 기록)
    // // 노드에서 노드간을 기록할 필요는 없음. 결국 호스트로 가는 것이기 때문에
    // for (int i = 0; i < nodes.size(); i++) {
    //   Node* node = nodes[i];
    //   Host* host = dynamic_cast<Host*>(node);
    //   if (host == nullptr) {  // node일 경우
        
    //   } else {  // host일 경우
    //     routingTable_.push_back(RoutingEntry{host->address(), links[i]});
    //   }
    // } 

  }
};

#endif