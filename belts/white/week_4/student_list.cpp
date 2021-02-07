#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>


struct BirthYear {
    int day;
    int month;
    int year;
};

struct Student {
    std::string forename;
    std::string surname;
    BirthYear date;
};


/* int main() {
    std::vector <Student> student_list;
    int N, M;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        Student student;

        std::cin >> student.forename;
        std::cin >> student.surname;
        std::cin >> student.date.day;
        std::cin >> student.date.month;
        std::cin >> student.date.year;

        student_list.push_back(student);
    }

    std::cin >> M;

    for (int i = 0; i < M; i++) {
        std::string request;
        int student_number;
        Student current_student;

        std::cin >> request;
        std::cin >> student_number;
        student_number--;

        if (request == "name" && student_number >= 0 &&
            student_number < N) {
            current_student = student_list[student_number];
            std::cout << current_student.forename << " " <<
                      current_student.surname << std::endl;

        } else if (request == "date" && student_number >= 0
                   && student_number < N) {
            current_student = student_list[student_number];
            std::cout << current_student.date.day << "." <<
                      current_student.date.month << "." <<
                      current_student.date.year << std::endl;

        } else {
            std::cout << "bad request" << std::endl;
        }
    }
    return 0;
} */

