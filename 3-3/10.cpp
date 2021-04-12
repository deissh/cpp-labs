// Кудявцев К. А. ИПБ-20; 3.3 #10

/*
Задача 10.
В последовательности символов, оканчивающихся точкой, найти наиболее часто встречающийся символ
*/

#include <iostream>
#include "string"

int readStr() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    auto str = readStr();

    char pChar = str.at(0);
    uint pCount = 1;

    for (auto ch : str) {
        if (pCount == 0) {
            pChar = ch;
            pCount = 1;
            continue;
        }

        if (pChar != ch)
            pCount -= 1;
        else
            pCount += 1;
    }

    std::cout << "most popular: " << pChar;

    return 0;
}