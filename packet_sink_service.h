#ifndef PACKET_SINK_SERVICE_H
#define PACKET_SINK_SERVICE_H

#include "service.h"
#include <string>

class PacketSinkService : public Service {
private:
  int total_packet;
  PacketSinkService(Host *host, short port);
public:
  virtual void receive(Packet *packet) override;
  int totalPacket() { return total_packet; }
};

#endif