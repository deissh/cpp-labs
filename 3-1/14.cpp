// Кудявцев К. А. ИПБ-20; 3.1 #14

/*
Задача 14.
Дана непустая последовательность целых чисел, за которой следует ноль (признак конца последовательности).
 Найти порядковый номер последнего отрицательного числа этой последовательности.
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

    int idx = -1;
    while (x != 0) {
        if (x < 0)
            idx = i;

        i++;
        x = readInt();
    }

    if (idx != -1)
        std::cout << "idx=" << idx;
    else
        std::cout << "not exist";

    return 0;
}