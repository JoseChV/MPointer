//
// Created by jose on 17/09/18.
//

#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H


#include <iostream>
#include "Node.h"

class LinkedList {
private:
    Node *head = nullptr;
public:

    ///inserta un nodo al final de la lista
    void insert(int* address, int ID){
        Node *temp = new Node();
        temp->setAddress(address);
        temp->setID(ID);
        if(head == nullptr){
            this->head = temp;
        }else{
            Node *actual = this->head;
            while(actual->getNext() != nullptr){
                actual = actual->getNext();
            }
            actual->setNext(temp);
        }
    }
    ///imprime la lista
    void print(){
        Node *temp = this->head;
        std::cout<<"printing"<<std::endl;
        if(head== nullptr){
            std::cout<<"empty list"<<std::endl;
        }else {
            while (temp->getNext() != nullptr) {
                std::cout << temp->getAddress() << std::endl;
                temp = temp->getNext();
            }
            std::cout << temp->getAddress() << std::endl;
        }
    }
    ///borra un nodo de la lista segun su ID
    void deleteNode(int ID) {
        Node *actual = this->head;

        if(actual==this->head){
            this->head = actual->getNext();
        }else{
            while (actual->getNext()->getID() != ID) {
                actual = actual->getNext();
            }
            actual->setNext(actual->getNext()->getNext());
        }
    }
};


#endif //MPOINTER_LINKEDLIST_H
