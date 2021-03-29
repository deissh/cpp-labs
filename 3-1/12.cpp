// Кудявцев К. А. ИПБ-20; 3.1 #12

/*
Задача 12.
Дана последовательность из n целых чисел, среди которых есть хотя бы одно отрицательное число.
 Найти величину наибольшего среди отрицательных чисел этой последовательности.
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

    int x = readInt();
    int minInt = x;

    while (i < n) {
        x = readInt();
        if (x < 0 && x < minInt)
            minInt = x;

        i++;
    }

    std::cout << "min=" << minInt;

    return 0;
}