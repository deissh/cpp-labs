// Кудявцев К. А. ИПБ-20; 3.1 #17

/*
Задача 17.
Дана последовательность из n целых чисел.
Найти порядковый номер первого положительного числа этой последовательности.
 */

#include <iostream>

int readInt() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    int x = readInt();
    int i = 1;

    while (x <= 0) {
        x = readInt();
        i++;
    }

    std::cout << "idx=" << i;

    return 0;
}
