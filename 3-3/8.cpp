// Кудявцев К. А. ИПБ-20; 3.3 #8

/*
Задача 8.
В последовательности символов, оканчивающихся точкой, удалить все пробелы.
*/

#include <iostream>
#include "string"

std::string readStr() {
    std::string val;

    std::cout << "> ";

    char ch;
    do {
        std::cin >> ch;
        val.push_back(ch);
    } while (ch != '.');

    return val;
}

int main() {
    auto str = readStr();

    for (auto ch : str) {
        if (ch != ' ') continue;

        str.replace(str.find(' '), 1, "");
    }

    std::cout << "out: " << str;

    return 0;
}