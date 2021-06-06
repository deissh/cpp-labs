// Кудявцев К. А. ИПБ-20; 3.9 #9

/*
Задача 9.
Любое арифметическое выражение может быть записано в виде обратной польской записи,
 где операции следуют после операндов. Например, выражение «1 + 2» можно записать как «1 2 +»,
 а выражение «(2 + 3) * (3 – 1)» можно записать как «2 3 + 3 1 – *».
 Реализовать подпрограмму вычисления выражения, заданного в виде обратной польской записи.
 Для решения данной задачи использовать стек. Вычисление организовать следующим образом: когда встречается число,
 поместить его в стек, когда встречается операция, из стека извлечь два операнда, над ними выполнить операцию,
 а результат поместить в стек. После вычислений в стеке останется одно число, оно и является результатом.
 */

#include <iostream>
#include <sstream>
#include <stack>

std::string readStr() {
    std::string val;

    std::cout << "> ";

    std::string ch;
    do {
        std::cin >> ch;
        val += ' ' + ch;
    } while (!ch.ends_with('\n'));

    return val;
}

int main() {
    std::stack<int> q;

    auto v = readStr();
    auto s = std::istringstream(v);

    std::string exp;
    while (getline(s, exp, ' ')) {
        int num;
        if (sscanf(exp.data(), "%d", &num) != EOF) {
            q.push(num);
            continue;
        }

        auto x = q.top();
        q.pop();
        auto y = q.top();
        q.pop();

        switch (exp[0]) {
            case '+':
                q.push(x + y);
                break;
            case '-':
                q.push(x - y);
                break;
        }
    }

    std::cout << "result=" << q.top();

    return 0;
}