// Кудявцев К. А. ИПБ-20; 3.2 #3B

/*
Задача 3в.
Дано предложение, оканчивающееся точкой. Найти
в) первое слово, начинающееся с заданной буквы
*/

#include <iostream>
#include <string>
#include <vector>

auto readChar() {
    char val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

auto readStr() {
    std::string val;
    std::cin >> val;

    return val;
}

int main() {
    std::cout << "enter letter" << "\n";
    auto startCh = readChar();

    std::cout << "enter str" << "\n" << "> ";

    std::string input;
    do {
        input = readStr();

        if (input.starts_with(startCh)) {
            std::cout << input << "\n";
            break;
        }
    } while (!input.ends_with("."));

    return 0;
}