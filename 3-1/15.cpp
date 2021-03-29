// Кудявцев К. А. ИПБ-20; 3.1 #15

/*
Задача 15.
Дана последовательность из n целых чисел.
Найти порядковый номер последнего числа этой последовательности, превосходящего заданное число b.
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
    int b = readInt();

    int x = readInt();
    int i = 1;
    int idx = -1;

    while (i < n) {
        i++;
        if (x > b)
            idx = i;

        x = readInt();
    }

    if (idx != -1)
        std::cout << "idx=" << idx;
    else
        std::cout << "not exist";

    return 0;
}
