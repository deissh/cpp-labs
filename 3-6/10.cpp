// Кудявцев К. А. ИПБ-20; 3.6 #10

/*
Задача 10.
Определить, является ли заданный целочисленный массив, упорядоченным по возрастанию,
 упорядоченным по убыванию или не упорядоченным.
 Оформить алгоритм анализа данных в массиве в виде подпрограммы.
*/

// файл содержит список чисел (раздлеитель пробел или новая строка)

#include <iostream>
#include <algorithm>
#include <fstream>

//auto isSorted(const int *arr, int n) {
//    return std::is_sorted(&arr[0], &arr[n - 1]);
//}

std::string isSorted(const int *arr, int n) {
    if (n == 1 || n == 0) return "asc";

    std::string res, tmp;
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] < arr[i])
            tmp = "asc";
        else if (arr[i - 1] > arr[i])
            tmp = "desc";

        if (tmp != res && !res.empty())
            return "none";

        res = tmp;
    }

    return res;
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

    auto arr = new int[n];

    for (int j = 0; j < 10; ++j)
        stream >> arr[j];

    std::cout << "isSorted=" << isSorted(arr, n);

    return 0;
}