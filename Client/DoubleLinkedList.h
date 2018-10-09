//
// Created by jose on 21/09/18.
//

#ifndef MPOINTER_DOUBLELINKEDLIST_H
#define MPOINTER_DOUBLELINKEDLIST_H


#include <iostream>
#include "DoubleNode.h"
#include "MPointer.h"

class DoubleLinkedList {
private:
    DoubleNode* head;
    DoubleNode* end;
public:
    DoubleLinkedList(){
        this->head= nullptr;
        this->end= nullptr;
    }

    ///inserta un nuevo nodo con el valor de data al final de la lista
    void insert(int data){
        DoubleNode* temp = new DoubleNode();
        temp->setData(data);
        if(this->head == nullptr){
            this->head = temp;
            this->end = temp;
        }else {
            DoubleNode* actual = this->head;
            while (actual->getNext() != nullptr) {
                actual = actual->getNext();
            }

            actual->setNext(temp);
            temp->setPrevious(actual);
            this->end=temp;
        }
    }
    ///imprime la lista
    void print(){
        DoubleNode *temp = this->head;
        std::cout<<"printing"<<std::endl;
        while(temp->getNext()!= nullptr){
            std::cout<<temp->getData()<<std::endl;
            temp = temp->getNext();
        }
        std::cout<<temp->getData()<<std::endl;
    }
    ///aplica quicksort
    void quickSort(){
        quickSortAux(head,end);
    }
    ///funcion auxiliar de quicksort
    void quickSortAux(DoubleNode* l, DoubleNode* h){

        if(h!= nullptr && l != h && l != h->getNext()){

            DoubleNode* p = partition(l, h);
            quickSortAux(l, p->getPrevious());
            quickSortAux(p->getNext(), h);
        }
    }
    ///funcion auxiliar de quicksort para obtener la particion
    DoubleNode* partition(DoubleNode* l, DoubleNode* h){

        int x = h->getData();

        DoubleNode *i = l->getPrevious();


        for(DoubleNode *j = l; j!=h; j=j->getNext()){
            if(j->getData() <= x){
                std::cout<<j->getData()<<"<"<<x<<std::endl;
                if(i== nullptr){
                    i = l;
                }else{
                    i = i->getNext();
                }
                swap(i,j);
            }
        }
        if(i== nullptr){
            i = l;
        }else{
            i = i->getNext();
        }

        swap(i,h);
        return i;
    }
    ///intercambia los valores de dos nodos utilizandos MPointers
    void swap(DoubleNode* a, DoubleNode* b){
        MPointer<int> ptr1;
        MPointer<int> ptr2;

        ptr1 = MPointer<int>::New();
        ptr2 = MPointer<int>::New();

        ptr1 = a->getData();
        ptr2 = b->getData();

        int t = &ptr1;

        ptr1 = &ptr2;

        ptr2 = t;

        a->setData(&ptr1);
        b->setData(&ptr2);


    }
    ///aplica bubble sort
    void bubbleSort(){

        MPointer<int> ptr1;
        MPointer<int> ptr2;


        ptr1 = MPointer<int>::New();
        ptr2 = MPointer<int>::New();

        for (DoubleNode* i = this->head; i->getNext()!= nullptr; i=i->getNext()) {
            for (DoubleNode* j = this->head; j->getNext() != nullptr; j=j->getNext()) {
                // Step 1
                ptr1 = j->getData();
                ptr2 = j->getNext()->getData();
                // Step 2
                if (&ptr1 > &ptr2) {
                    j->getNext()->setData(&ptr1);
                    j->setData(&ptr2);
                }
            }
        }
    }
    ///aplica insertion sort
    void insertionSort(){
        DoubleNode* temp = new DoubleNode;
        DoubleNode* h = this->head;
        temp->setNext(h);
        while(h->getNext()!= nullptr){
            if(h->getData() <= h->getNext()->getData()){
                std::cout<<h->getData()<<" es menor que "<<h->getNext()->getData()<<std::endl;
                h = h->getNext();
            }else{
                std::cout<<h->getData()<<" mayor "<<h->getNext()->getData()<<std::endl;
                DoubleNode* actual = temp;
                while(actual->getNext()->getData() <= h->getNext()->getData()){
                    actual = actual->getNext();
                }
                DoubleNode* i = h->getNext();
                h->setNext(i->getNext());
                i->setNext(actual->getNext());
                actual->setNext(i);
            }
        }
    }
};


#endif //MPOINTER_DOUBLELINKEDLIST_H