// Кудявцев К. А. ИПБ-20; 3.1 #19

/*
Задача 19.
Дана последовательность из n целых чисел. Определить, со скольких отрицательных чисел она начинается.
 */

#include <iostream>

int readInt() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    int n = readInt();
    int count = 0, x;

    for (int i = 0; i < n; ++i) {
        x = readInt();

        if (x < 0) count++;
        else {
            std::cout << "count=" << count;
            return 0;
        }
    }

    std::cout << "count=0";

    return 0;
}
