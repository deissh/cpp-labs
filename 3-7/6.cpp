// Кудявцев К. А. ИПБ-20; 3.7 #6

/*
Задача 6.
Реализовать подпрограмму удаления из списка L всех элементов, имеющих четные значения.
 */

#include <iostream>
#include <algorithm>

struct Node {
    Node *next;
    int data;
};

void printList(struct Node* n) {
    std::cout << "list=[";
    while (n != nullptr) {
        std::cout << n->data <<",";
        n = n->next;
    }
    std::cout << "]\n";
}

void insertNode(Node*& lRef, int data) {
    auto node = new Node();
    node->data = data;
    node->next = lRef;
    lRef = node;
}

void deleteNode(Node*& lRef) {
    if (lRef == nullptr) {
        std::cout << "err: empty node\n";
        return;
    }

    auto t = lRef;
    lRef = lRef->next;

    delete (t);
}

Node* del(Node*& lRef) {
    if (lRef == nullptr)
        return nullptr;

    if (auto node = del(lRef->next); lRef->data % 2 != 0) {
        lRef->next = node;
        return lRef;
    } else {
        deleteNode(lRef);
        return node;
    }
}

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int main() {
    Node* head = nullptr;

    for (int i = 0; i < 10; ++i)
        insertNode(head, i);

    printList(head);

    del(head);

    printList(head);

    return 0;
}