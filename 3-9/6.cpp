// Кудявцев К. А. ИПБ-20; 3.9 #6

/*
Задача 6.
Вводится последовательность чисел. Вывести сначала все четные числа, затем нечетные в обратном порядке.
 */

#include <iostream>
#include <stack>
#include <queue>

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int main() {
    std::queue<int> s;
    std::stack<int> q;

    auto v = readInt("> ");
    while (v != 0) {
        (v % 2)
            ? q.push(v)
            : s.push(v);

        v = readInt("> ");
    }

    while (!s.empty()) {
        std::cout << s.front();
        s.pop();
    }

    while (!q.empty()) {
        std::cout << q.top();
        q.pop();
    }

    return 0;
}