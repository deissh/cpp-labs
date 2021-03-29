// Кудявцев К. А. ИПБ-20; 3.2 #6

/*
Задача 6.
Проверить, совпадает ли в заданной последовательности символов количество открывающихся и закрывающихся круглых скобок
*/

#include <iostream>
#include "string"

std::string readStr() {
    std::string val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    auto str = readStr();

    int op = 0;
    for (auto ch : str) {
        switch (ch) {
            case '(': op++; break;
            case ')': op--; break;
            default: break;
        }
    }

    if (op == 0) std::cout << "eq";
    else std::cout << "not eq";

    return 0;
}