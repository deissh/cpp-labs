// Кудявцев К. А. ИПБ-20; 3.9 #9

/*
Задача 9.
Любое арифметическое выражение может быть записано в виде обратной польской записи,
 где операции следуют после операндов. Например, выражение «1 + 2» можно записать как «1 2 +»,
 а выражение «(2 + 3) * (3 - 1)» можно записать как «2 3 + 3 1 - *».
 Реализовать подпрограмму вычисления выражения, заданного в виде обратной польской записи.
 Для решения данной задачи использовать стек. Вычисление организовать следующим образом: когда встречается число,
 поместить его в стек, когда встречается операция, из стека извлечь два операнда, над ними выполнить операцию,
 а результат поместить в стек. После вычислений в стеке останется одно число, оно и является результатом.
 */

#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>

std::string readStr() {
    std::string val;

    getline(std::cin, val);

    return val;
}

int main() {
    std::stack<double> q;

    auto v = readStr();
    auto s = std::istringstream(v);

    std::string exp;
    while (getline(s, exp, ' ')) {
        float num = 0;
        if (sscanf(exp.data(), "%f", &num) >= 1) {
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
            case '*':
                q.push(x * y);
                break;
            case '/':
                q.push(x / y);
                break;
            case '^':
                q.push(std::pow(x, y));
                break;
        }
    }

    std::cout << "result=" << q.top();

    return 0;
}