// Кудявцев К. А. ИПБ-20; 3.5 #5a

/*
Задача 5a.
С помощью текстового редактора подготовить файл с заданным именем, в котором содержится последовательность целых чисел. Написать программу, которая:
a) добавляет в файл k чисел и выводит весь файл на экран;
*/

#include <iostream>
#include <fstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

std::string readStr(char *str) {
    std::cout << str;

    std::string ch;
    std::cin >> ch;

    return ch;
}

int readInt(char *str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int main() {
    auto filename = readStr("filename=");
    auto k = readInt("k=");

    std::fstream stream;
    stream.open(filename, std::ios::out | std::ios::in);

    if (!stream.is_open())
        return 1;

    stream.seekg(0, std::ios::end);

    for (int i = 0; i < k; ++i)
        stream << readInt("> ") << ' ';

    stream.seekg(std::ios::beg);

    int tmp;
    while (stream >> tmp)
        std::cout << tmp << ',';

    stream.close();

    return 0;
}
