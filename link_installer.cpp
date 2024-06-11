#include "link_installer.h"

Link *LinkInstaller::install(Node *a, Node *b) {
    Link *link = new Link(a, b);
    a->links.push_back(link);
    b->links.push_back(link);
    
    return link;
}

Link *LinkInstaller::install(Node *a, Node *b, double delay) {
    Link *link = new Link(a, b, delay);
    a->links.push_back(link);
    b->links.push_back(link);
    
    return link;
}