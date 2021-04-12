// Кудявцев К. А. ИПБ-20; 3.3 #8a

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
    std::string match;
    std::cin >> match;

    auto total = 0;
    auto i = input.find(match);
    while (i != -1) {
        total ++;
        input.replace(i, match.size(), "");
        i = input.find(match);
    }

    std::cout << "total=" << total;

    return 0;
}