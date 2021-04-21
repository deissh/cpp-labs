// Кудявцев К. А. ИПБ-20; 3.4 #9

/*
Задача 10.
С клавиатуры вводится строка, состоящая из нескольких слов, разделенных знаками препинания.
Найти длину самого длинного слова после первой запятой.
*/

#include <iostream>
#include <string>

std::string readStr() {
    std::string val;

    std::cout << "> ";

    std::string ch;
    do {
        std::cin >> ch;
        val += ' ' + ch;
    } while (!ch.ends_with("."));

    return val;
}

int main() {
    auto str = readStr();

    auto word_count = 0;
    std::string max_word;
    std::string tmp;

    for (auto ch : str) {
        if (ch == ' ' or (ch >= 44 and ch <= 46)) {
            if (tmp.length() > max_word.length() && word_count >= 1) {
                max_word = tmp;
            }

            if (ch == ',')
                word_count++;

            tmp = "";
            continue;
        }

        tmp += ch;
    }

    std::cout << max_word << '\n';

    return 0;
}