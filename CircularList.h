//
// Created by hojas on 20/04/25.
//

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H


template <typename T>
class CircularList {
    struct Node {
        T data;
        Node* next;
        Node* prev;

        explicit Node(T data) : data(data), next(nullptr), prev(nullptr){}


    };

    Node* head;
public:
    CircularList();
    ~CircularList();

    void push_front(T data);
    void push_back(T data);
    T pop_front();
    T pop_back();

    void print_list();
    void clear();
    bool is_empty();

    void intersect(CircularList <T>& other);
    void reverse();

    void insert(T data, int index);
    void remove(T data, int index);


};



#endif //CIRCULARLIST_H
