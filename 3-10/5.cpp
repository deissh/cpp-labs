// Кудявцев К. А. ИПБ-20; 3.10 #5

/*
Задача 5.
С помощью рекурсивной функции найти произведение элементов одномерного массива.
 */

#include <iostream>

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int mul(int arr[], int n) {
    return (n > 0)
        ? mul(arr, n - 1) * arr[n - 1]
        : 1;
}

int main() {
    auto n = readInt("n=");
    int arr[n];

    for (int i = 0; i < n; ++i)
        arr[i] = readInt("> ");

    std::cout << "mul=" << mul(arr, n) << '\n';

    return 0;
}