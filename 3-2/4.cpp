// Кудявцев К. А. ИПБ-20; 3.2 #4

/*
Задача 4.
Дана текущая дата в формате дд.мм.гггг и день недели.
Определить, какая дата и день недели будет через n дней
*/

#include <iostream>
#include <string>

std::string readStr() {
    std::string val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

int readInt() {
    int val;

    std::cout << "> ";
    std::cin >> val;

    return val;
}

bool isLeap(int y) {
    return (y % 100 != 0 && y % 4 == 0 || y % 400 == 0);
}

int offsetDays(int d, int m, int y) {
    int offset = d;

    switch (m - 1) {
        case 11:
            offset += 30;
        case 10:
            offset += 31;
        case 9:
            offset += 30;
        case 8:
            offset += 31;
        case 7:
            offset += 31;
        case 6:
            offset += 30;
        case 5:
            offset += 31;
        case 4:
            offset += 30;
        case 3:
            offset += 31;
        case 2:
            offset += 28;
        case 1:
            offset += 31;
    }

    if (isLeap(y) && m > 2) offset += 1;

    return offset;
}

void calcOffsetDays(int offset, int y, int *dayInt, int *monthInt)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++) {
        if (offset <= month[i]) break;
        offset = offset - month[i];
    }

    *dayInt = offset;
    *monthInt = i;
}

int main() {
    std::cout << "enter days to offset" << "\n";
    auto N = readInt();

    std::cout << "enter date (example 23.10.2020)" << "\n";
    auto buff = readStr();

    int day, month, year;
    sscanf(buff.c_str(), "%2d.%2d.%4d", &day, &month, &year);

    int origOffset = offsetDays(day, month, year);
    int remDays = (isLeap(year) ? 366 : 365) - origOffset;

    int newYear, offset;
    if (N <= remDays) {
        newYear = year;
        offset = origOffset + N;
    } else {
        N -= remDays;
        newYear = year + 1;
        int cDays = isLeap(newYear) ? 366 : 365;

        while (N >= cDays) {
            N -= cDays;
            newYear++;
            cDays = isLeap(newYear) ? 366 : 365;
        }

        offset = N;
    }

    int m2, d2;
    calcOffsetDays(offset, newYear, &d2, &m2);

    printf("%d.%d.%d", d2, m2, newYear);

    return 0;
}