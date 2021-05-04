// Кудявцев К. А. ИПБ-20; 3.9 #5

/*
Задача 5.
Вводится последовательность чисел. Вывести все числа последовательности в обратном порядке.
 */

#include <iostream>
#include <stack>

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int main() {
    std::stack<int> q;

    auto v = readInt("> ");
    while (v != 0) {
        q.push(v);
        v = readInt("> ");
    }

    while (!q.empty()) {
        std::cout << q.top();
        q.pop();
    }

    return 0;
}