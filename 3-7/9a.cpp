// Кудявцев К. А. ИПБ-20; 3.7 #9a

/*
Задача 9а.
Дан кольцевой список вещественных чисел. Реализовать следующие подпрограммы:
а) проверка наличия в списке двух одинаковых элементов;
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

bool search(Node* lRef, int value) {
    auto tmp = lRef;
    do {
        if (tmp->data == value)
            return true;

        tmp = tmp->next;
    } while (lRef != tmp->next);

    return false;
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

    tmp = head;
    do {
        if (search(tmp->next, tmp->data)) {
            std::cout << "duplicate " << tmp->data << '\n';
            return 0;
        }

        tmp = tmp->next;
    } while (head != tmp);

    std::cout << "no duplicates";
    return 0;
}