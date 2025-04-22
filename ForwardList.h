//
// Created by hojas on 20/04/25.
//

#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H


template <typename T>
class ForwardList {
    struct Node {
        T data;
        Node* next;

        explicit Node(T data) : data(data), next(nullptr){}

    };

    Node* head;
public:
    ForwardList();
    ~ForwardList();

    void push_front(T data); // O(1);
    void push_back(T data); // O(n);
    T pop_front(); // O(1); -> return data
    T pop_back(); // O(n); -> return

    void print_list();
    void clear();
    bool is_empty();

    void sort(); // insertion sort;
    void merge_sort();

    void intersect();
    void reverse();

    void insert(T data, int index);
    void remove(int index);

};



#endif //FORWARD_LIST_H
