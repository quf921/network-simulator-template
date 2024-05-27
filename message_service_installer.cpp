#include "message_service_installer.h"

MessageService *MessageServiceInstaller::install(Host *host) {
    MessageService *messageService;
    // MessageService *messageService = new MessageService(host,  host->clientPort, this->destAddress_, this->destPort_);
    // MessageService *messageService = new MessageService(host,  Service::port_, this->destAddress_, this->destPort_);
    ServiceInstaller::install(host, messageService);

    return messageService;
}