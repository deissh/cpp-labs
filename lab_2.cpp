#include <iostream>
#include <fstream>
#include <sstream>

std::string readStr() {
    std::cout << "filename=";

    std::string ch;
    std::cin >> ch;

    return ch;
}

void parseEvents(std::ifstream& stream, std::ofstream& out_winter, std::ofstream& out_summer) {
    std::string title;
    int year, month, day;

    std::string tmp, dates;
    while (getline(stream, tmp)) {
        auto s = std::istringstream(tmp);
        getline(s, title, ',');
        getline(s, dates);

        sscanf(dates.data(), "%d, %d, %d", &year, &month, &day);

        switch(month) {
            case 1:
            case 2:
            case 12:
                out_winter << tmp << std::endl;
                break;
            case 6:
            case 7:
            case 8:
                out_summer << tmp << std::endl;
                break;
        }
    };
}

int main() {
    auto filename = readStr();

    std::ifstream stream(filename);
    std::ofstream out_winter("winter_" + filename);
    std::ofstream out_summer("summer_" + filename);

    if (!stream.is_open() || !out_winter.is_open() || !out_summer.is_open())
        return 1;

    parseEvents(stream, out_winter, out_summer);

    stream.close();
    out_winter.close();
    out_summer.close();
    return 0;
}
