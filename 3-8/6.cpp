// Кудявцев К. А. ИПБ-20; 3.8 #6

/*
Задача 6.
Реализовать подпрограмму, которая вставляет в кольцевой
 список L новый элемент F перед каждым вхождением элемента Е.
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
Node<T>* end(Node<T>* ref) {
    if (ref == nullptr) return nullptr;

    auto last = ref;
    while (last->next != nullptr)
        last = last->next;

    return last;
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
void insert_before(Node<T>*& ref, Node<T>* refNode, T value) {
    if (refNode == nullptr or ref == nullptr)
        return;

    auto pNode = new Node<T>{};

    pNode->data = value;

    pNode->prev = refNode->prev;

    refNode->prev = pNode;

    pNode->next = refNode;

    if (pNode->prev != nullptr)
        pNode->prev->next = pNode;
    else
        ref = pNode;
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

char readChr(const std::string& str) {
    std::cout << str;

    char ch;
    std::cin >> ch;

    return ch;
}

int main() {
    Node<char>* l = nullptr;
    auto el = readChr("search=");
    auto ins = readChr("insert_before=");

    std::cout << "list (dot char is the end of the input)\n";

    auto v = readChr("> ");
    while (v != '.') {
        push_back(l, v);
        if (v == el) insert_before(l, end(l), ins);

        v = readChr("> ");
    }

    printList(l);

    return 0;
}