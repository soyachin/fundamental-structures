//
// Created by hojas on 20/04/25.
//

#ifndef QUEUE_H
#define QUEUE_H


template <typename T>
class Queue {
    struct Node {
        T data;
        Node* next;
        Node* prev;

        explicit Node(T data) : data(data), next(nullptr), prev(nullptr){}


    };
    Node* tail; // head is tail->prev
public:
    Queue();
    ~Queue();
    void enqueue(const T& data);
    T dequeue();
    T front() const;
    T back() const;
    bool is_empty() const;
    void clear();
    void print() const;
    void intersect(Queue<T>& other);

};



#endif //QUEUE_H
