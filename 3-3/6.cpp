// Кудявцев К. А. ИПБ-20; 3.3 #6

/*
Задача 6б.
Преобразовать массив a по следующему правилу:
b) элементы массива циклически сдвинуть на 2 позиции влево.
*/

#include <iostream>

const int N = 7;

int main() {
    int arr[N] = {1,2,3,4,5,6,7};
    for (auto el : arr) std::cout << el << ',';
    std::cout << '\n';

    int tmp = arr[0];
    int tmp2 = arr[1];

    for (int i = 0; i < (N - 1); ++i) {
        arr[i] = arr[i + 2];
    }

    arr[N-2] = tmp;
    arr[N-1] = tmp2;

    for (auto el : arr) std::cout << el << ',';

    return 0;
}