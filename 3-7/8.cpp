// Кудявцев К. А. ИПБ-20; 3.7 #8

/*
Задача 8.
Реализовать подпрограмму,
 которая в кольцевом списке R из каждой группы подряд
 идущих одинаковых элементов оставляет только одного представителя.
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
        if (tmp->next->data == tmp->data) {
            auto x = tmp->next;
            tmp->next = x->next;
            delete x;
        } else {
            tmp = tmp->next;
        }
    } while (head != tmp);

    tmp = head;

    std::cout << "list=[";
    do {
        std::cout << tmp->data <<",";
        tmp = tmp->next;
    } while (head != tmp);
    std::cout << "]\n";
    return 0;
}