cmake_minimum_required(VERSION 3.12)
project(Client)

set(CMAKE_CXX_STANDARD 14)


add_executable(Client main.cpp MPointer_init.cpp MPointer_init.h DoubleNode.cpp DoubleNode.h DoubleLinkedList.cpp DoubleLinkedList.h MPointer.cpp MPointer.h MPointerGC.cpp MPointerGC.h Node.cpp Node.h LinkedList.cpp LinkedList.h)