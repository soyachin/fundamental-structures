//
// Created by hojas on 20/04/25.
//

#ifndef STACK_H
#define STACK_H

/*
 *  Para el stack solo es necesario un punteros a next;
 *
*/

template<typename T>
class Stack { // estructura LIFO (last in, first out)
    struct Node {
        T data;
        Node* next;

        explicit Node(T data) : data(data), next(nullptr){}

    };

    Node* top;
public:
    Stack();
    ~Stack();
    T pop();
    void push(T data);
    bool is_empty();
    void clear();
    T peek(); // get top es llamado peek to avoid confussions

};



#endif //STACK_H
