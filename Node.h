//
// Created by jose on 21/09/18.
//

#ifndef MPOINTER_NODE_H
#define MPOINTER_NODE_H


class Node {
private:
    int *address;
    int ID;
    Node *next = nullptr;
public:
    int* getAddress() const;

    int getID() const;

    void setID(int ID);

    Node* getNext() const;
    void setAddress(int* address);
    void setNext(Node *next);
};


#endif //MPOINTER_NODE_H
