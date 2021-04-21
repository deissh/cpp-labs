// Кудявцев К. А. ИПБ-20; 3.4 #11

/*
Задача 11.
Вводится последовательность слов, признак конца – точка.
Распечатать все слова в алфавитном порядке.
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readStr() {
    std::vector<std::string> val;

    std::cout << "> ";

    std::string ch;
    do {
        std::cin >> ch;
        val.push_back(ch);
    } while (!ch.ends_with("."));

    return val;
}

int main() {
    auto words = readStr();

    std::sort(words.begin(), words.end());

    for (const auto& word : words)
        std::cout << word << ' ';

    return 0;
}