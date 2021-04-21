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
    std::cout << "warn: numbers in the file must be on each line\n";
    auto filename = readStr();

    std::ifstream stream;
    stream.open(filename);

    std::ofstream negStream;
    negStream.open("neg_" + filename);

    std::ofstream posStream;
    posStream.open("pos_" + filename);

    if (!stream.is_open())
        return 1;

    int tmp;

    while (stream >> tmp)
        (tmp >= 0 ? posStream : negStream) << tmp << ' ';

    return 0;
}