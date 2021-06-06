// Кудявцев К. А. ИПБ-20; 3.8 #5

/*
Задача 5.
С клавиатуры вводится последовательность латинских букв, оканчивающаяся точкой.
 Среди символов есть специальный символ «*», появление которого требует удаления предыдущей буквы.
 При этом k знаков «*» подряд удаляют k предыдущих букв, если такие есть.
 Вывести на экран исправленную последовательность.
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
        if (v == '*') pop_back(l);
        else push_back(l, v);

        v = readChr("> ");
    }

    printList(l);

    return 0;
}