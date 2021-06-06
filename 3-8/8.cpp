// Кудявцев К. А. ИПБ-20; 3.8 #8

/*
Задача 8.
Реализовать подпрограмму, которая из всех одинаковых
значений кольцевого списка оставляет только последние.
 */

#include <iostream>
#include <algorithm>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template <typename T>
void push_front(Node<T>*& ref, T value) {
    auto pNode = new Node<T>{
        .data=value,
        .next=ref,
        .prev=nullptr,
    };
    if (ref != nullptr) ref->prev = pNode;

    ref = pNode;
}

template <typename T>
void push_back(Node<T>*& ref, T value) {
    auto pNode = new Node<T>{
        .data=value,
        .next=nullptr,
        .prev=nullptr,
    };
    auto last = ref;

    if (ref == nullptr) {
        pNode->prev = nullptr;
        ref = pNode;
        return;
    }

    while (last->next != nullptr)
        last = last->next;

    last->next = pNode;
    pNode->prev = last;
}

template <typename T>
void pop_back(Node<T>* ref) {
    if (ref == nullptr) return;

    auto last = ref;

    while (last->next != nullptr)
        last = last->next;

    last->prev->next = nullptr;

    delete last;
}

template <typename T>
void pop(Node<T>* ref) {
    if (ref == nullptr) return;

    ref->next->prev = ref->prev;
    ref->prev->next = ref->next;

    delete ref;
}

template <typename T>
void printList(Node<T>* node) {
    std::cout<<"list=[";
    while (node != nullptr) {
        std::cout << node->data <<",";
        node = node->next;
    }
    std::cout<<"]\n";
}

template <typename T>
Node<T>* find(Node<T>* ref, T value) {
    while (ref != nullptr) {
        if (ref->data == value)
            return ref;

        ref = ref->next;
    }

    return nullptr;
}

template <typename T>
Node<T>* head(Node<T>* ref) {
    if (ref == nullptr) return nullptr;

    auto last = ref;
    while (last->prev != nullptr)
        last = last->prev;

    return last;
}

char readChr(const std::string& str) {
    std::cout << str;

    char ch;
    std::cin >> ch;

    return ch;
}

int main() {
    Node<char>* l = nullptr;

    auto v = readChr("> ");
    while (v != '.') {
        push_back(l, v);

        v = readChr("> ");
    }

    printList(l);

    auto ref = l;
    while (ref != nullptr and ref->next != nullptr) {
        if (ref->data == ref->next->data)
            pop(ref);

        ref = ref->next;
    }

    printList(l);

    return 0;
}