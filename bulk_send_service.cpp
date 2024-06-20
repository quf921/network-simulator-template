#include "bulk_send_service.h"

void BulkSendService::receive(Packet *packet) {
    return;
}

void BulkSendService::send() {
    for (int i = startTime_; i < stopTime_; i+=delay_) {
        std::function<void()> function = [this]() { 
            std::string data;
            for (int i = 0; i < 512; i++) {
                data.append(std::to_string(i));
            }
            Packet *packet = new Packet(host_->address(), destAddress_, port_, destPort_, data);
            std::stringstream ss;
            ss << "sending data";
            log(ss.str());
            host_->send(packet);
        };

        Simulator::schedule(i + Simulator::now(), function);
    }
}