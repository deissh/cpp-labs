// Кудявцев К. А. ИПБ-20; 3.3 #8a

/*
Задача 8a.
С клавиатуры вводится строка.
a. Заменить все вхождения подстроки «я» на подстроку «ты».
*/

#include <iostream>

int readInt() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int main() {
    std::cout << "N ";
    auto n = readInt();
    std::cout << "M ";
    auto m = readInt();

    int* matrix = new int[n * m];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << "[" << i << ":" << j << "]=";
            matrix[i + i * j] = readInt();
        }
    }

    for (int i = 1; i <= n; ++i) {
        auto total = 0;

        for (int j = 1; j <= m; ++j) {
            if (matrix[j + i * j] < 0) total ++;
        }

        std::cout << " m=" << total;
    }

    std::cout << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cout << matrix[i + i * j] << ',';
    }

    delete [] matrix;
    return 0;
}