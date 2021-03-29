// Кудявцев К. А. ИПБ-20; 3.1 #13

/*
Задача 13.
Дана последовательность из n целых чисел. Найти последнее отрицательное число этой последовательности.
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
    int i = 1;

    int idx = -1;
    while (i <= n) {
        int x = readInt();
        if (x < 0)
            idx = i;

        i++;
    }

    if (idx != -1)
        std::cout << "idx=" << idx;
    else
        std::cout << "not exist";

    return 0;
}