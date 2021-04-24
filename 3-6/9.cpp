// Кудявцев К. А. ИПБ-20; 3.6 #7

/*
Задача 9.
Определить, является ли строка палиндромом,
 описав булевскую функцию идентификации палиндрома.
 */

#include <iostream>
#include <algorithm>

bool isPal(const std::string& s){
    if (s.empty()) return false;

    auto size = s.size() - 1;
    for (int i = 0; i < size / 2; ++i) {
        if (s.at(i) == s.at(size - i)) continue;

        return false;
    }

    return true;
}

std::string readStr() {
    std::cout << "input=";

    std::string ch;
    std::cin >> ch;

    return ch;
}

int main() {
    auto str = readStr();
    std::cout << "isPal=" << isPal(str);

    return 0;
}