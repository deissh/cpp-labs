// Кудявцев К. А. ИПБ-20; 3.5 #5b

/*
Задача 5b.
С помощью текстового редактора подготовить файл с заданным именем, в котором содержится последовательность целых чисел. Написать программу, которая:
b) находит максимальное и минимальное числа в измененном файле;
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

    int tmp, vMin, vMax;

    while (stream >> tmp) {
        if (tmp > vMax) vMax = tmp;
        if (tmp < vMin) vMin = tmp;
    };

    std::cout << "min=" << vMin << '\n';
    std::cout << "min=" << vMax << '\n';

    return 0;
}