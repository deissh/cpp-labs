// Кудявцев К. А. ИПБ-20; 3.2 #5

/*
Задача 5.
Дана последовательность символов, после которой идет знак "*" – признак конца последовательности.
Определить, является ли эта последовательность символов правильной записью целого числа (возможно со знаком)
*/

#include <iostream>
#include "string"

int main() {
    char ch;
    bool err = false;

    std::cin >> ch;
    if ((ch < 48 || ch > 57) && ch != 43)
        err = true;

    while (ch != '*' && err != true) {
        if ((ch < 48 || ch > 57) && ch != 43)
            err = true;
        else
            std::cin >> ch;
    }

    std::cout << "err=" << err;
    return 0;
}