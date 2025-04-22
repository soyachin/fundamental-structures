//
// Created by hojas on 20/04/25.
//

#include "ForwardList.h"

#include <iostream>
#include <stdexcept>


template<typename T>
ForwardList<T>::ForwardList() : head(nullptr) {};

template<typename T>
ForwardList<T>::~ForwardList() {
    while (head != nullptr) {
        auto* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void ForwardList<T>::push_front(T data) {
    auto* newNode = Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void ForwardList<T>::push_back(T data) {
    auto* newNode = Node<T>(data);
    if (head == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    else {
        auto* curr = head;

        while (curr->next != nullptr) { // aquel cuyo next es nullptr.
            curr->next;
        }

        curr->next = newNode;

    }
}

template<typename T>
T ForwardList<T>::pop_front() {
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    auto* temp=head;
    T value = temp->value;
    head = head->next; // Head avanza
    delete temp;
    temp = nullptr;
    return value;
}

template<typename T>
T ForwardList<T>::pop_back() {
    if (head == nullptr)
        throw std::out_of_range("List is empty");
    auto* temp = head;

    if (head->next == nullptr) { // Solo un elemento
        T value = head->value;
        delete head;
        head = nullptr;
        return value;
    }

    while (temp->next->next != nullptr) {
        temp = temp->next; // el previo del último
    }

    T value = temp->next->data;

    delete temp->next; // eliminar el siguiente del penúltimo, osea el último
    temp->next = nullptr;
    return value;

}

template<typename T>
void ForwardList<T>::print_list() {
    auto* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value << " ";
    }

}

template<typename T>
void ForwardList<T>::clear() {
    while (head != nullptr)
        pop_front();
}

template<typename T>
bool ForwardList<T>::is_empty() {
    if (head == nullptr) return true;
    return false;
}

template<typename T>
void ForwardList<T>::sort() { // insertion sort
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    auto apple = new Node<T>(0);

    while (current != nullptr) {
        next = current->next;
        // usamos el dummy apple
        prev = apple;

        // mientras que el next no sea null y el dato del siguiente del next sea menor del dato del current:
        while (prev->next != nullptr && prev->next->data < current->data) {
            prev = prev->next; // itera
        }
        current->next = prev->next; // el siguiente del current se vuelve el siguiente del prev
        prev->next = current;

        current = next;
    }

    head = apple->next; // eliminamos el dummy apple
    delete apple;
}

template<typename T>
void ForwardList<T>::merge_sort() {
}

template<typename T>
void ForwardList<T>::intersect() {
}

template<typename T>
void ForwardList<T>::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Guardar el siguiente nodo
        current->next = prev; // Invertir el puntero -> reverse
        prev = current;
        current = next;
    }
    head = prev; // Actualizar

}

template<typename T>
void ForwardList<T>::insert(T data, int index) {
    if (index == 0) {
        push_front(data);
    }
    auto* temp = head;
    for (int i = 1; i < index && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "Fuera de rango." << std::endl;
        return;
    }

    auto* newNode = new Node<T>(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

template<typename T>
void ForwardList<T>::remove(int index) {
    if (index == 0) pop_front();

    auto* it = head;
    for (int i = 1; i < index && it->next != nullptr; ++i) {
        it = it->next;
    }

    if (it->next == nullptr) {
        std::cout << "Fuera de rango." << std::endl;
        return;
    }

    auto* temp = it->next;
    it->next = temp->next;

    delete temp;

}