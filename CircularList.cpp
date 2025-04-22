

#include "CircularList.h"

#include <iostream>
#include <stdexcept>

template<typename T>
CircularList<T>::CircularList() : head(nullptr) {}

template<typename T>
CircularList<T>::~CircularList() {
    if (head) {
        Node* current = head;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

}

template<typename T>
void CircularList<T>::push_front(T data) {
    Node* newNode = new Node(data);
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }

    else {
        Node* tail = head->prev;
        newNode->next = head; // Apunta a la cabeza antigua
        newNode->prev = tail; // Apunta a la cola
        head->prev = newNode; // La cabeza antigua apunta al nuevo nodo
        tail->next = newNode; // La cola apunta al nuevo nodo
        head = newNode; // Actualiza la cabeza -> push_front
    }
}

template<typename T>
void CircularList<T>::push_back(T data) {
    Node* newNode = new Node(data);
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else {
        Node* tail = head->prev;
        newNode->next = head; // Apunta a la cabeza
        newNode->prev = tail; // Apunta a la cola
        tail->next = newNode; // La cola apunta al nuevo nodo
        head->prev = newNode; // La cabeza apunta al nuevo nodo

    }

}

template<typename T>
T CircularList<T>::pop_front() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    if (head->next == head) {
        T data = head->data;
        delete head;
        head = nullptr;
        return data;
    }

    Node* tail = head->prev;
    T data = head->data;
    Node* newHead = head->next;
    tail->next = newHead; // La cola apunta a la nueva cabeza
    newHead->prev = tail; // La nueva cabeza apunta a la cola
    delete head; // Elimina la antigua cabeza
    head = newHead; // Actualiza la cabeza
    return data;

}

template<typename T>
T CircularList<T>::pop_back() {
    // Elimina el último nodo de la lista circular
    if (!head) {
        throw std::out_of_range("List is empty");
    }
    if (head->next == head) {
        T data = head->data;
        delete head;
        head = nullptr;
        return data;
    }
    Node* tail = head->prev;
    T data = tail->data;
    Node* newTail = tail->prev;
    newTail->next = head; // La nueva cola apunta a la cabeza
    head->prev = newTail; // La cabeza apunta a la nueva cola
    delete tail; // Elimina la antigua cola
    return data;

}

template<typename T>
void CircularList<T>::print_list() {
    // Imprime la lista circular
    if (!head) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        while (head) {
            std::cout << head->data << " ";
            head = head->next;
            if (head == head->next) {
                break;
            }
        }
    }
    
}

template<typename T>
void CircularList<T>::clear() {
    if (head) {
        Node* current = head;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
}

template<typename T>
bool CircularList<T>::is_empty() {
    return head == nullptr;
}

template<typename T>
void CircularList<T>::intersect(CircularList<T>& other) {
    std::cout << "Intersecting lists" << std::endl;
}

template<typename T>
void CircularList<T>::reverse() {
    if (!head) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    do {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    head->prev = current;
    head = prev; // Actualiza la cabeza
    Node* tail = head->prev;
    tail->next = head; // La cola apunta a la cabeza
    head->prev = tail; // La cabeza apunta a la cola
}

template<typename T>
void CircularList<T>::insert(T data, int index) {
    if (index < 0) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        push_front(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* current = head;
    for (int i = 0; i < index - 1; ++i) {
        if (!current) {
            throw std::out_of_range("Index out of range");
        }
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;




}

template<typename T>
void CircularList<T>::remove(T data, int index) {

    if (index < 0) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        push_back(data);
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}