// Кудявцев К. А. ИПБ-20; 3.3 #12

/*
Задача 12.
С клавиатуры вводится строка символов. Заменить в строке каждую точку троеточием.
*/

#include <iostream>
#include <string>

std::string readStr() {
    std::cout << "> ";

    std::string ch;
    std::cin >> ch;

    return ch;
}

int main() {
    auto input = readStr();

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] != '.') continue;

        input.replace(i, 1, "...");
        i += 2;
    }

    std::cout << "result=" << input;

    return 0;
}