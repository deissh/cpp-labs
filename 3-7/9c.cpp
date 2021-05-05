// Кудявцев К. А. ИПБ-20; 3.7 #9в

/*
Задача 9в.
Дан кольцевой список вещественных чисел. Реализовать следующие подпрограммы:
в) перенос в конец первого элемента списка.
 */

#include <iostream>
#include <algorithm>

struct Node {
    Node *next;
    int data;
};

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

void printList(Node* lRef) {
    auto tmp = lRef;

    std::cout << "list=[";
    do {
        std::cout << tmp->data <<",";
        tmp = tmp->next;
    } while (lRef != tmp);
    std::cout << "]\n";
}

int main() {
    auto n = readInt("n=");
    if (n <= 1) return 1;

    Node* head = new Node{
        .next=nullptr,
        .data=readInt("> ")
    };
    head->next = head;

    auto tmp = head;
    for (int i = 2; i <= n; i++) {
        tmp->next = new Node{
            .next=head,
            .data=readInt("> ")
        };

        tmp = tmp->next;
    }

    printList(head);

    head = head->next;

    printList(head);

    return 0;
}