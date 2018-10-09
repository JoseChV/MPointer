#include <iostream>
#include "LinkedList.h"
#include "MPointer.h"
#include "DoubleNode.h"
#include "DoubleLinkedList.h"
int main() {

    MPointerGC::getInstance();
    std::thread processThread(MPointerGC::startThread);


    /*for (uint i = 0; i <10 ; ++i){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << i << "-ésima corrida del hilo principal" << std::endl;
    }*/



    MPointer<int> ptrA = MPointer<int>::New();
    MPointer<int> ptrB = MPointer<int>::New();
    MPointer<int> ptrC = MPointer<int>::New();
    MPointer<int> ptrD = MPointer<int>::New();

    ptrA=51;
    *ptrB=41;
    ptrC=55;
    ptrD = &ptrC;

    std::cout<<"IDs"<<std::endl;
    std::cout<<ptrA.getID()<<std::endl;
    std::cout<<ptrB.getID()<<std::endl;
    std::cout<<ptrC.getID()<<std::endl;

    ptrC = ptrA;

    std::cout<<ptrC.getID()<<std::endl;
    std::cout<<ptrD.getID()<<std::endl;


    std::cout<<"Valores"<<std::endl;

    std::cout<<&ptrA<<std::endl;
    std::cout<<&ptrB<<std::endl;
    std::cout<<&ptrC<<std::endl;
    std::cout<<&ptrD<<std::endl;

    /*std::cout<<"Direcciones"<<std::endl;
    MPointerGC::getInstance()->list->print();
*/



    /*DoubleLinkedList* a = new DoubleLinkedList;
    a->insert(1);
    a->insert(67);
    a->insert(14);
    a->insert(3);
    a->insert(4);
    a->insert(76);
    a->insert(8);
    a->insert(89);
    a->insert(42);
    a->insert(12);
    a->insert(4);
    a->insert(4);
    a->insert(7);
    a->insert(6);
    a->insert(5);
    a->insert(4);
    a->insert(2);
    a->insert(67);
    a->insert(15);
    a->insert(23);
    a->insert(4);
    a->insert(80);
    a->print();


    std::cout<<"sorting"<<std::endl;
    a->quickSort();
    a->insertionSort();
    a->bubbleSort();
    std::cout<<"done"<<std::endl;

    a->print();
    */
    processThread.join();

    return 0;
};