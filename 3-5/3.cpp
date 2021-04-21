// Кудявцев К. А. ИПБ-20; 3.5 #3

/*
Задача 3.
Ввести последовательность из n целых чисел и записать их в текстовый файл, имя которого запросить.
*/

#include <iostream>
#include <fstream>

std::string readStr() {
    std::cout << "filename=";

    std::string ch;
    std::cin >> ch;

    return ch;
}

int readInt() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    auto filename = readStr();

    std::ofstream stream;
    stream.open(filename);

    std::cout << "input file content\n";
    auto input = readInt();
    while (input != 0) {
        stream << input << ' ';
        input = readInt();
    };

    return 0;
}