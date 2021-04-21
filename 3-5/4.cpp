// Кудявцев К. А. ИПБ-20; 3.5 #4

/*
Задача 4.
Запросить имя файла, считать из него числа, вычисляя их сумму, и вывести на экран выражение вида:
36+28+42+...=...
*/

#include <iostream>
#include <fstream>

std::string readStr() {
    std::cout << "filename=";

    std::string ch;
    std::cin >> ch;

    return ch;
}

int main() {
    auto filename = readStr();

    std::ifstream stream;
    stream.open(filename);

    if (!stream.is_open())
        return 1;

    auto sum = 0;
    int tmp;
    while (stream >> tmp) sum += tmp;

    std::cout << "sum=" << sum << '\n';

    return 0;
}