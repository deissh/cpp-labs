// Кудявцев К. А. ИПБ-20; 3.7 #7

/*
Решить задачу Иосифа Флавия (считалка).
 В круг стоят N человек. До тех пор, пока не останется ровно один человек,
 поочередно исключается каждый K-ый.
 Требуется определить номер начальной позиции оставшегося человека.
 При решении использовать кольцевой список.
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
    Node* head = new Node{.next=nullptr, .data=1,};
    head->next = head;

    auto n = readInt("n=");
    auto k = readInt("k=");

    auto tmp = head;
    for (int i = 2; i <= n; i++) {
        tmp->next = new Node{.next=head, .data=i};

        tmp = tmp->next;
    }

    while(tmp != tmp->next) {
        for (int i = 1; i < k; i++)
            tmp = tmp->next;

        auto x = tmp->next;
        tmp->next = x->next;
        delete x;
    }

    std::cout << "alive=" << tmp->data << '\n';
    return 0;
}