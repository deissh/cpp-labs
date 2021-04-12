// Кудявцев К. А. ИПБ-20; 3.3 #6a

/*
Задача 6а.
Преобразовать массив a по следующему правилу:
a) элементы массива расположить в обратном порядке (транспонировать);
*/

#include <iostream>

const int N = 7;

int main() {
    int arr[N] = {1,2,3,4,5,6,7};

    int tmp;
    for (int i = 0; i < N / 2; ++i) {
        tmp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = tmp;
    }

    for (auto el : arr) std::cout << el << ',';

    return 0;
}