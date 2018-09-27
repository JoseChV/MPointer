cmake_minimum_required(VERSION 3.12)
project(MPointer)

set(CMAKE_CXX_STANDARD 14)

add_executable(MPointer main.cpp MPointerGC.cpp MPointerGC.h LinkedList.cpp LinkedList.h Node.cpp Node.h DoubleLinkedList.cpp DoubleLinkedList.h DoubleNode.cpp DoubleNode.h MPointer.h)