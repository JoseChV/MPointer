//
// Created by jose on 21/09/18.
//

#ifndef MPOINTER_DOUBLENODE_H
#define MPOINTER_DOUBLENODE_H


class DoubleNode {
private:
    int data;
    DoubleNode* next;
    DoubleNode* previous;
public:
    DoubleNode *getPrevious() const;

    void setPrevious(DoubleNode *previous);

    int getData() const;

    void setData(int data);

    DoubleNode *getNext() const;

    void setNext(DoubleNode *next);
};


#endif //MPOINTER_DOUBLENODE_H
