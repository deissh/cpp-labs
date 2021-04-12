// Кудявцев К. А. ИПБ-20; 3.3 #8c

/*
Задача 8b.
С клавиатуры вводится строка.
b. Найти количество вхождений заданной подстроки в эту строку.
*/

#include <iostream>
#include <string>

std::string readStr() {
    std::string val;

    std::cout << "> ";

    std::string ch;
    do {
        std::cin >> ch;
        val += ' ' + ch;
    } while (!ch.ends_with("."));

    return val;
}

int main() {
    auto input = readStr();
    auto total = 0;

    for (auto ch : input) {
        if (ch >= 44 and ch <= 46)
            total ++;
    }

    std::cout << "total=" << total;

    return 0;
}