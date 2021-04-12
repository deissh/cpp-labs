// Кудявцев К. А. ИПБ-20; 3.3 #7

/*
Задача 7.
Элементы массива данных типа int расположить в обратном порядке.
*/

#include <iostream>

const int N = 7;

int main() {
    int arr[N] = {1,2,3,4,5,6,7};

    int tmp;
    for (int i = 0; i < N / 2; ++i) {
        tmp = arr[i];
        arr[i] = arr[6-i];
        arr[6-i] = tmp;
    }

    for (auto el : arr) std::cout << el << ',';

    return 0;
}