// Кудявцев К. А. ИПБ-20; 3.1 #20

/*
Задача 20.
Дана последовательность из n целых чисел. Определить, сколько из них принимает наибольшее значение.
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
    int x = readInt();

    int max_count = 1;
    int max_value = x;

    for (int i = 0; i < n - 1; ++i) {
        x = readInt();

        if (x == max_value) max_count++;
        else if (x > max_value) {
            max_value = x;
            max_count = 1;
        }
    }

    std::cout << "max=" << max_value << " count=" << max_count;

    return 0;
}
