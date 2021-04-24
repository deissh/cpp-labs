// Кудявцев К. А. ИПБ-20; 3.6 #7

/*
Задача 7.
Написать программу нахождения наибольшего общего делителя двух целых чисел,
 оформив алгоритм нахождения НОД в виде подпрограммы.
 */

#include <iostream>
#include <algorithm>

int nod(int a, int b) {
    while (a != b) {
        if (a > b) std::swap(a, b);
        b = b - a;
    }

    return a;
}

int main() {
    std::cout << "nod=" << nod(10, 34);

    return 0;
}