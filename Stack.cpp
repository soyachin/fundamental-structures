//
// Created by hojas on 20/04/25.
//

#include "Stack.h"

#include <stdexcept>

template<typename T>
Stack<T>::Stack() : top(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    while (top != nullptr) {
        auto* temp = top;
        top = top->next; // sigue avanzando
        delete temp;
    }
}

template<typename T>
T Stack<T>::pop() { // es basicamente un pop_front
    if (top == nullptr) throw std::out_of_range("Stack is empty");

    auto* temp = top;
    T value = temp->value;
    top = top->next;
    delete temp;
    temp = nullptr;
    return value;
}

template<typename T>
void Stack<T>::push(T data) { // push_front
    auto* newNode = Node<T>(data);
    newNode->next = top;
    top = newNode;
}

template<typename T>
bool Stack<T>::is_empty() {
    if (top == nullptr) return true;
    return false;
}

template<typename T>
void Stack<T>::clear() {
    while (top) {
        pop();
    }
}

template<typename T>
T Stack<T>::peek() {
    if (top == nullptr)
        throw std::runtime_error("Stack is empty");

    return top->value;
}