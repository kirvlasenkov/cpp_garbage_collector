#include <iostream>
#include <string>
#include <sstream>
#include <stack>

/*
int main() {
    int first = 0;
    int n = 0;
    std::stringstream str;

    std::cin >> first >> n;

    if (n != 0) {
        for (int i = 0; i < n; i++) {
            str << '(';
        }
    } else {
        std::cout << first;
        return 0;
    }

    str << first << ')';

    for (int i = 0; i < n; i++) {
        int number;
        char sign;
        std::cin >> sign >> number;

        if (i != n - 1)
            str << ' ' << sign << ' ' << number << ')';
        else
            str << ' ' << sign << ' ' << number;


    }
    std::cout << str.str();

    return 0;
}
*/