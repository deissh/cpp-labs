// Кудявцев К. А. ИПБ-20; 3.2 #a

/*
Задача 3а.
Дано предложение, оканчивающееся точкой. Найти
а) количество слов в предложении
*/

#include <iostream>
#include <string>

auto readStr() {
    std::string val;
    std::cin >> val;

    return val;
}

int main() {
    std::cout << "enter str" << "\n" << "> ";

    std::string input;
    auto count = 0;

    do {
        input = readStr();
        count++;
    } while (!input.ends_with("."));

    std::cout << "total words=" << count;

    return 0;
}