// Кудявцев К. А. ИПБ-20; 3.2 #Б

/*
Задача 3в.
Дано предложение, оканчивающееся точкой. Найти
в) кол-во слов, начинающееся с заданной буквы
*/

#include <iostream>
#include <string>

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
    auto count = 0;

    do {
        input = readStr();

        if (input.starts_with(startCh)) count++;
    } while (!input.ends_with("."));

    std::cout << "words=" << count;

    return 0;
}