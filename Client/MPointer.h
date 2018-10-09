///
/// Created by kevinfgn on 9/16/18.
///

#include <stdlib.h>
#include <iostream>
#include "MPointerGC.h"

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

template<class T>

class MPointer {

private:

    T *data;
    int ID = 0;

public:


    ///Este metodo que se encarga de asignar un
    /// espacio de memoria a un puntero segun su tipo

    MPointer<T>() {
        data = new T();
        ID = MPointerGC::getInstance()->idAssigner;
    }
    ///Metodo para liberar la data del puntero.
    ~MPointer<T>(){
        MPointerGC::getInstance()->removePointer(this->ID);
        delete data;

    }

    ///Este metodo que se encarga
    /// de asignar un valor a un puntero.

    void operator=(T value) {
        *data = value;
    }


    ///Este metodo que se encarga de
    ///verificar si dos punteros son del mismo tipo,
    ///si son iguales cambia la data del MPointer
    ///con la data con la que se esta comparando
    ///sino compila es que son de diferente tipo.

    void operator=(MPointer<T> mPointer) {
        *data = &mPointer;
        ID = mPointer.ID;

    }


    ///Este metodo que se encarga de
    ///devolver el valor de un puntero al utilizar el operador &.

    T operator&() {
        return *data;
    }
    ///Este metodo que se encarga
    ///de devolver un puntero al utilizar el operador*

    T& operator*() {
        return *this->data;
    }


    static MPointer<T> New() {

        MPointer<T>* ptr = new MPointer<T>();
        MPointerGC::getInstance()->addPointer((int*)ptr, ptr->ID);
        return *ptr;
    }

    int getID(){
        return ID;
    }
    void setID (int _ID){
        ID = _ID;
    }

};
#endif //MPOINTER_MPOINTER_H