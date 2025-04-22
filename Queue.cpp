

#include "Queue.h"

#include <iostream>
#include <stdexcept>

template<typename T>
Queue<T>::Queue() : tail(nullptr) {}

template<typename T>
Queue<T>::~Queue() {
    while (!is_empty()) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::enqueue(const T &data) { // this is basically push_back
    Node* newNode = new Node(data);
    if (!tail) {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else {
        Node* head = tail->prev;
        newNode->next = head; // Apunta a la cabeza
        newNode->prev = tail; // Apunta a la cola
        tail->next = newNode; // La cola apunta al nuevo nodo
        head->prev = newNode; // La cabeza apunta al nuevo nodo
        tail = newNode; // Actualiza la cola -> enqueue
    }
}

template<typename T>
T Queue<T>::dequeue() {
    if (!tail) {
        throw std::out_of_range("List is empty");
    }

    if (tail == tail->next) { // 1 elemento
        T data = tail->data;
        delete tail;
        tail = nullptr;
        return data;
    }
    else {
        Node* head = tail->prev;
        Node* newHead = head->next;
        T data = head->data;
        delete head;
        tail->prev = newHead; // el nuevo tail apunta a la nueva cabeza
        newHead->prev = tail; // la nueva cabeza apunta a la cola
        return data;
    }
}

template<typename T>
T Queue<T>::front() const {
    return tail->prev->data; //
}

template<typename T>
T Queue<T>::back() const {
    return tail->data;
}

template<typename T>
bool Queue<T>::is_empty() const {
    return tail == nullptr;
}

template<typename T>
void Queue<T>::clear() {
    if (tail) {
        Node* current = tail;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != tail);
    }
    tail = nullptr;
}

template<typename T>
void Queue<T>::print() const {
    while (tail) {
        std::cout << tail->data << " ";
        tail = tail->next;
        if (tail == tail->next) {
            break;
        }
    }
}

template<typename T>
void Queue<T>::intersect(Queue<T> &other) {
    std::cout << "Intersecting queues" << std::endl;
}