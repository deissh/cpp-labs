// Кудявцев К. А. ИПБ-20; 3.9 #8

/*
Задача 8.
Вводится последовательность символов, сбалансированная по скобкам.
Требуется для каждой пары соответствующих открывающей
и закрывающей скобок вывести на экран номера их позиций в последовательности.
 */

#include <iostream>
#include <stack>

struct AstBracket {
    char ch;
    int start_pos;
    int end_pos;
};

std::string readStr(const std::string& str) {
    std::cout << str;

    std::string ch;
    std::cin >> ch;

    return ch;
}

int main() {
    std::string semStart = "{[(";
    std::string semEnd = "}])";

    std::stack<AstBracket> stack;

    auto str = readStr("> ");

    for (int i = 0; i < str.length(); i++) {
        auto ch = str[i];

        if (semStart.find(ch) != std::string::npos) {
            auto el = AstBracket {
                .ch = ch,
                .start_pos = i,
                .end_pos = -1,
            };
            stack.push(el);
            continue;
        }

        AstBracket el = stack.top();
        if (semEnd.find(ch) == std::string::npos
            or semStart.find(el.ch) != semEnd.find(ch)
        )
            continue;

        stack.pop();
        el.end_pos = i;

        std::cout << "start=" << el.start_pos << ",end=" << el.end_pos << '\n';
    }

    return 0;
}