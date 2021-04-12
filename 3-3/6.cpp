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

    for (int k = 0; k < 2; ++k) {
        int tmp = arr[0];

        for (int i = 0; i < N - 1; ++i)
            arr[i] = arr[i + 1];

        arr[N-1] = tmp;
    }

    for (auto el : arr) std::cout << el << ',';

    return 0;
}