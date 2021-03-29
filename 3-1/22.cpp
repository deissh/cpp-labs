// Кудявцев К. А. ИПБ-20; 3.1 #22

/*
 Задача 22.
 Дана непустая последовательность ненулевых целых чисел, за которой следует ноль (признак конца последовательности).
 Определить, сколько раз в этой последовательности меняется знак
 (например, в после-довательности 1, – 34, 8, 14, – 5 знак меняется 3 раза).
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
    int prev = x;
    int count = 0;

    while (x != 0) {
        x = readInt();

        if ((x < 0 and prev > 0) or (x > 0 and prev < 0))
            count++;

        prev = x;
    }

    std::cout << "count=" << count;

    return 0;
}
