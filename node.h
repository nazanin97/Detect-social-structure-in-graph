
#ifndef node_h
#define node_h

class node {
public:
    int data{};
    int degree{};             
    node* link;
    node* dlink;
};

#endif 
