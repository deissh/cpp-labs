// Кудявцев К. А. ИПБ-20; 3.3 #9

/*
Задача 9.
В последовательности символов, оканчивающихся точкой, удалить все вхождения заданного символа.
*/

#include <iostream>
#include "string"

std::string readStr() {
    std::string val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

char readChar() {
    char val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    auto ch = readChar();
    auto str = readStr();

    str.replace(str.find(ch), 1, "");

    std::cout << "out: " << str;

    return 0;
}