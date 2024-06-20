#ifndef PACKET_SINK_SERVICE_H
#define PACKET_SINK_SERVICE_H

#include "service.h"
#include <string>

class PacketSinkService : public Service {
private:
  friend class PacketSinkServiceInstaller;
  
  int total_packet;
  PacketSinkService(Host *host, short port) : Service(host, port) {}

  virtual std::string name() override { return "PacketSinkService"; }
public:
  virtual void receive(Packet *packet) override;
  void send() override {};
  int totalPacket() { return total_packet; }
};

#endif