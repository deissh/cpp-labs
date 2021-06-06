// Кудявцев К. А. ИПБ-20; 3.7 #6

/*
Задача 5.
С клавиатуры вводится последовательность латинских букв, оканчивающаяся точкой.
 Среди символов есть специальный символ «*», появление которого требует удаления предыдущей буквы.
 При этом k знаков «*» подряд удаляют k предыдущих букв, если такие есть.
 Вывести на экран исправленную последовательность.
 */

#include <iostream>
#include <algorithm>
#include <list>

char readChr(const std::string& str) {
    std::cout << str;

    char ch;
    std::cin >> ch;

    return ch;
}

int main() {
    // в std либе std::list сделан поверх двунаправленного списка
    // в другой лабе руками напишу свою реализацию
    std::list<char> l;

    auto v = readChr("> ");
    while (v != '.') {
        if (v == '*') l.pop_back();
        else l.push_back(v);

        v = readChr("> ");
    }

    { // output
        std::cout << "result=";
        for (auto el : l) std::cout << el;
        std::cout << '\n';
    }

    return 0;
}