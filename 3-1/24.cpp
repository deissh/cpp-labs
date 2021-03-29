// Кудявцев К. А. ИПБ-20; 3.1 #24

/*
 * Задача 24.
 Дана непустая последовательность ненулевых целых чисел,
 за которой следует ноль (признак конца последовательности).
 Определить длину первой монотонно возрастающей подпоследовательности чисел этой последовательности.
 */

#include <iostream>

int readInt() {
    int val;

    std::cin >> val;

    return val;
}

int main() {
    int x = readInt();
    int prev = x;
    int count = 1;

    while (x != 0) {
        x = readInt();

        if ((x > prev and (x > 0 and prev > 0)) or (x < prev and (x < 0 and prev < 0))) {
            count++;
        } else {
            std::cout << count << std::endl;
            return 0;
        }

        prev = x;
    }

    return 0;
}
