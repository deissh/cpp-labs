// Кудявцев К. А. ИПБ-20; 3.6 #6

/*
Задача 6.
Написать программу нахождения вещественных корней линейного ax+b=0 и квадратного ax2+bx+c=0 уравнений,
оформив алгоритм решения уравнения в виде перегруженной функции Equation.
*/

#include <iostream>
#include <cmath>

void Equation(int a, int b) {
    std::cout << "x=" << (-b / a) << '\n';
}
void Equation(int a, int b, int c) {
    auto dis = pow(b, 2) - 4 * a * c;

    if (dis == 0)
        std::cout << "x=" << (-b / (2 * a)) << '\n';
    else if (dis > 0)
        std::cout
            << "x1=" << (-b - sqrt(dis)) / (2 * a)
            << '\n'
            << "x2=" << (-b + sqrt(dis)) / (2 * a)
            << '\n';
    else
        std::cout << "err\n";
}

int main() {
    std::cout << "case ax+b=0\n";
    Equation(2, 10);

    std::cout << "\ncase ax2+bx+c=0\n";
    Equation(2, 4, 2);
    Equation(1, 6, 1);
    Equation(5, 0, 1);

    return 0;
}