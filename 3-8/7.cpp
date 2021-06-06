// Кудявцев К. А. ИПБ-20; 3.8 #7

/*
Задача 7.
Дан кольцевой список, содержащий целые числа.
 Реализовать подпрограмму определения количества различных элементов списка.
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
void pop_back(Node<T>*& ref) {
    if (ref == nullptr) return;

    auto last = ref;

    while (last->next != nullptr)
        last = last->next;

    last->prev->next = nullptr;

    delete last;
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

char readChr(const std::string& str) {
    std::cout << str;

    char ch;
    std::cin >> ch;

    return ch;
}

int main() {
    Node<char>* l = nullptr;
    int count = 0;

    auto v = readChr("> ");
    while (v != '.') {
        if (find(l, v) == nullptr)
            count ++;

        push_back(l, v);
        v = readChr("> ");
    }

    std::cout << "count=" << count;

    return 0;
}