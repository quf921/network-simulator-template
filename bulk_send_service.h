#ifndef BULK_SEND_SERVICE_H
#define BULK_SEND_SERVICE_H

#include "host.h"
#include "service.h"
#include "simulator.h"

#define PACKET_SIZE 512

class BulkSendService : Service {
  friend class BulkSendServiceInstaller;
  Address destAddress_;
  short destPort_;
  double delay_;
  double startTime_;
  double stopTime_;

  std::string data;

private:
  BulkSendService(Host *host, Address destAddress, short destPort,
                  double delay = 1, double startTime = 0,
                  double stopTime = 10.0) : 
                  Service(host, -1), destAddress_(destAddress), destPort_(destPort),
                  delay_(delay), startTime_(startTime), stopTime_(stopTime) {}
  
  virtual std::string name() override { return "BulkSendService"; }
public:
  void receive(Packet *packet) override;
  void send();
};

#endif