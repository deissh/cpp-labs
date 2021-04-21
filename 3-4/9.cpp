// Кудявцев К. А. ИПБ-20; 3.4 #9

/*
Задача 9.
С клавиатуры вводится строка. Заменить все буквы английского алфавита на соответствующие байтовые коды.
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
    for (auto ch : readStr())
        std::cout << int(ch) << ' ';

    return 0;
}