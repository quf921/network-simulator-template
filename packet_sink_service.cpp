#include "packet_sink_service.h"

void PacketSinkService::receive(Packet *packet) {
    total_packet += packet->dataString().length();
}