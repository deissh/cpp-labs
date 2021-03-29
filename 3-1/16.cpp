// Кудявцев К. А. ИПБ-20; 3.1 #16

/*
Задача 16.
Дана непустая последовательность целых чисел, за которой следует ноль (признак конца последовательности).
Найти первое отрицательное число этой последовательности.
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

    while (x > 0) {
        x = readInt();
        i++;
    }

    if (x != 0)
        std::cout << "idx=" << i;
    else
        std::cout << "not exist";

    return 0;
}
