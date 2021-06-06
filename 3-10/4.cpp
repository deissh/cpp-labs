// Кудявцев К. А. ИПБ-20; 3.10 #4

/*
Задача 4.
С помощью рекурсивной функции найти сумму чисел от 1 до n.
 */

#include <iostream>

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int sum(int arr[], int n) {
    return (n > 0)
        ? sum(arr, n - 1) + arr[n - 1]
        : 0;
}

int main() {
    auto n = readInt("n=");
    int arr[n];

    for (int i = 0; i < n; ++i)
        arr[i] = readInt("> ");

    std::cout << "sum=" << sum(arr, n) << '\n';

    return 0;
}