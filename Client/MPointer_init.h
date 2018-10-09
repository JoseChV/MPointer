//
// Created by Ba on 2/10/2018.
//

#ifndef CLIENT_MPOINTER_INIT_H
#define CLIENT_MPOINTER_INIT_H

#include <iostream>
using namespace std;


class MPointer_init {

public:

    char address[20] = "127.0.0.1";
    int port;

    MPointer_init( int p)
    {

        port = p;
    }


};


#endif //CLIENT_MPOINTER_INIT_H
