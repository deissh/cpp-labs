// Кудявцев К. А. ИПБ-20; 3.5 #2e

/*
Задача 2e.
Анкета студента содержит следующие сведения: фамилия, пол, год рождения, курс, рост и оценки по математике,
физике, информатике, химии, экономике. Написать программу, которая выполняет следующие действия:
e) выводит фамилии, год рождения и средний балл студентов, сгруппировав их по курсам.*/

#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string firstName;
    std::string lastName;

    uint gender;
    std::string bdate;
    uint course;
    uint height;

    std::vector<uint> math;
    std::vector<uint> phys;
    std::vector<uint> inform;
    std::vector<uint> chem;
    std::vector<uint> econ;
};

void printStudent(const Student& stud) {
    std::cout << "last name: " << stud.lastName << '\n';
    std::cout << "bdate: " << stud.bdate << '\n';

    uint sum = 0;
    uint total = 0;

    for(auto score : stud.math) { sum += score; total++; }
    for(auto score : stud.phys) { sum += score; total++; }
    for(auto score : stud.inform) { sum += score; total++; }
    for(auto score : stud.chem) { sum += score; total++; }
    for(auto score : stud.econ) { sum += score; total++; }

    std::cout << "avg score: " << sum / total << "\n\n";
}

std::vector<uint> readScore() {
    auto vec = std::vector<uint>();

    auto n = 0;
    std::cout << "n=";
    std::cin >> n;

    auto tmp = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << "> ";
        std::cin >> tmp;

        vec.push_back(tmp);
    }

    return vec;
}

Student readStudent() {
    auto stud = Student{};

    std::cout << "first name: ";
    std::cin >> stud.firstName;

    std::cout << "last name: ";
    std::cin >> stud.lastName;

    std::cout << "gender (0 - male, 1 - female, ... - other): ";
    std::cin >> stud.bdate;

    std::cout << "bdate: ";
    std::cin >> stud.bdate;

    std::cout << "course: ";
    std::cin >> stud.course;

    std::cout << "height: ";
    std::cin >> stud.height;

    std::cout << "=== math scores ===\n";
    stud.math = readScore();

    std::cout << "=== phys scores ===\n";
    stud.phys = readScore();

    std::cout << "=== inform scores ===\n";
    stud.inform = readScore();

    std::cout << "=== chem scores ===\n";
    stud.chem = readScore();

    std::cout << "=== econ scores ===\n";
    stud.econ = readScore();

    return stud;
}

int main() {
    auto vec = std::vector<Student>();

    auto n = 0;
    std::cout << "students n=";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
        vec.push_back(readStudent());

    // 1- 4 course
    for (int i = 1; i <= 4; ++i) {
        std::cout << "=== " << i << " course ===\n";
        for (const auto& stud : vec) {
            if (stud.course != i) continue;

            printStudent(stud);
        }
    }

    return 0;
}