// Кудявцев К. А. ИПБ-20; 3.1 #21

/*
 Задача 21.
 Дана последовательность из n целых чисел.
 Определить количество чисел наиболее длинной подпоследовательности из подряд идущих нулей.
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

    int x;
    int l = 0;
    int max_l = 0;

    for (int i = 0; i < n; ++i) {
        x = readInt();

        if (x == 0) {
            l++;
        } else {
            if (l > max_l) {
                max_l = l;
            }

            l = 0;
        }
    }

    std::cout << "max=" << std::max(max_l, l);

    return 0;
}
