//
// Created by jose on 21/09/18.
//

#include "DoubleNode.h"

int DoubleNode::getData() const {
    return data;
}

void DoubleNode::setData(int data) {
    DoubleNode::data = data;
}

DoubleNode *DoubleNode::getPrevious() const {
    return previous;
}

DoubleNode *DoubleNode::getNext() const {
    return next;
}

void DoubleNode::setNext(DoubleNode *next) {
    DoubleNode::next = next;
}

void DoubleNode::setPrevious(DoubleNode *previous) {
    DoubleNode::previous = previous;
}
