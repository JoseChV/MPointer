//
// Created by jose on 17/09/18.
//

#ifndef MPOINTER_MPOINTERGC_H
#define MPOINTER_MPOINTERGC_H


#include <thread>
#include <chrono>
#include "LinkedList.h"

class MPointerGC {
private:
    static MPointerGC *instance;

    MPointerGC() = default;

public:
    int idAssigner;
    LinkedList *list = new LinkedList();
    static MPointerGC *getInstance(){

        if (MPointerGC::instance == nullptr) {
            instance = new MPointerGC();
        }
        return instance;
    }

    void addPointer(int *address, int ID) {
        list->insert(address,ID);
        idAssigner++;
    }

    void removePointer(int ID) {
        list->deleteNode(ID);
    }
    static void startThread(){
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << "Thread cicle complete" << std::endl;
        }

    }

};

#endif //MPOINTER_MPOINTERGC_H
