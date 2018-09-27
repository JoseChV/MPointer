#include <iostream>
#include "LinkedList.h"
#include "MPointer.h"
#include "DoubleNode.h"
#include "DoubleLinkedList.h"
int main() {

    //MPointerGC::getInstance()->start();

    /*
    MPointer<int> a = MPointer<int>::New();
    MPointer<int> b = MPointer<int>::New();
    MPointer<int> c = MPointer<int>::New();

    a=51;
    b=41;
    c=55;


    std::cout<<a.getID()<<std::endl;
    std::cout<<b.getID()<<std::endl;

    c = a;

    std::cout<<c.getID()<<std::endl;

    a= 5;
    std::cout<<&a<<std::endl;
    std::cout<<&c<<std::endl;

    MPointerGC::getInstance()->list->print();
*/


    DoubleLinkedList* a = new DoubleLinkedList;
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


    std::cout<<"quick sorting"<<std::endl;
    a->quickSort();
    std::cout<<"done"<<std::endl;

    a->print();

    return 0;
};