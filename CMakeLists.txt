cmake_minimum_required(VERSION 3.30)
project(fundamental_structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(fundamental_structures main.cpp
        ForwardList.cpp
        ForwardList.h
        DoubleLinkedList.cpp
        DoubleLinkedList.h
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h
        CircularList.cpp
        CircularList.h
        PriorityQueue.cpp
        PriorityQueue.h)
