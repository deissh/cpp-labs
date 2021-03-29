// Кудявцев К. А. ИПБ-20; 3.1 #23

/*
 Задача 23.
 Дано n вещественных чисел. Определить, образуют ли они воз-растающую последовательность.
 */

#include <iostream>

int readInt() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    std::cout << "n=";
    int n = readInt();

    int x = readInt();
    int prev = x;
    int count = 1;

    for (int i = 0; i < n - 1; ++i) {
        x = readInt();
        if (x < prev) {
            std::cout << "false";
            return 0;
        }

        prev = x;
    }
    std::cout << "true";

    return 0;
}
