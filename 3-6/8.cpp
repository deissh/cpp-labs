// Кудявцев К. А. ИПБ-20; 3.6 #8

/*
Задача 8.
Дано n групп чисел, в каждую из которых входит 10 целых чисел.
 Найти порядковый номер группы чисел с наибольшей разностью между максимальным и минимальным числами в группе.
 Алгоритм поиска разности между максимальным и минимальным числами оформить как функцию.
 */

// файл содержит список чисел (раздлеитель пробел или новая строка)

#include <iostream>
#include <algorithm>
#include <fstream>

auto diff(const int *arr) {
    auto [vMin, vMax] = std::minmax_element(
    &arr[0],
    &arr[9]
    );

    return *vMax - *vMin;
}

std::string readStr(const std::string& str) {
    std::cout << str;

    std::string ch;
    std::cin >> ch;

    return ch;
}

int readInt(const std::string& str) {
    std::cout << str;

    int ch;
    std::cin >> ch;

    return ch;
}

int main() {
    auto n = readInt("n=");
    auto filename = readStr("filename=");

    std::ifstream stream;
    stream.open(filename);

    if (!stream.is_open())
        return 1;

    auto group = new int[n][10];
    long int maxDiff = 0, maxDiffIdx = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j)
            stream >> group[i][j];

        if (auto v = diff(group[i]); v > maxDiff) {
            maxDiff = v;
            maxDiffIdx = i;
        }
    }

    std::cout << "maxDiff=" << maxDiff << "; groupIdx=" << maxDiffIdx + 1 << '\n';

    return 0;
}