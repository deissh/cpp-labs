// Кудявцев К. А. ИПБ-20; 3.3 #8a

/*
Задача 8a.
С клавиатуры вводится строка.
a. Заменить все вхождения подстроки «я» на подстроку «ты».
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

    auto i = input.find('i');
    while (i != -1) {
        input.replace(i, 1, "you");

        i = input.find('i');
    }

    std::cout << "result=" << input;

    return 0;
}