// Кудявцев К. А. ИПБ-20; 3.9 #7

/*
Задача 7.
Используя стек, выполнить проверку последовательности символов
на корректность расстановки трех типов скобок: «( )», «{ }», «[ ]».
 */

#include <iostream>
#include <stack>

std::string readStr(const std::string& str) {
    std::cout << str;

    std::string ch;
    std::cin >> ch;

    return ch;
}

int main() {
    std::string semStart = "{[(";
    std::string semEnd = "}])";

    std::stack<int> stack;

    auto str = readStr("> ");

    bool err;
    for (auto ch : str) {
        if (semStart.find(ch) != std::string::npos) {
            stack.push(ch);
            continue;
        }

        if (semEnd.find(ch) != std::string::npos
            and semStart.find(stack.top()) != semEnd.find(ch)
        )
            err = true;

        stack.pop();
    }

    std::cout << "err=" << ((err) ? "true" : "false");

    return 0;
}