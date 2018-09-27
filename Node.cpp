//
// Created by jose on 21/09/18.
//

#include "Node.h"

int* Node::getAddress() const {
    return address;
}
void Node::setAddress(int *address) {
    Node::address = address;
}
Node* Node::getNext() const{
    return next;
}
void Node::setNext(Node *next) {
    Node::next = next;
}

int Node::getID() const {
    return ID;
}

void Node::setID(int ID) {
    Node::ID = ID;
}
