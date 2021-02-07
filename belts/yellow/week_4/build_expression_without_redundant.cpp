#include <iostream>
#include <deque>
#include <string>



enum class Operation {
    Add,
    Sub,
    Mul,
    Div
};

struct Request {
    Operation operation;
    std::string number;
};


std::istream& operator>>(std::istream& str, Request& r) {
    std::string sign;
    std::string number;
    str >> sign >> number;

    if (sign == "+") {
        r.operation = Operation::Add;
        r.number = number;
    }

    else if (sign == "-") {
        r.operation = Operation::Sub;
        r.number = number;
    }

    else if (sign == "*") {
        r.operation = Operation::Mul;
        r.number = number;
    }

    else if (sign == "/") {
        r.operation = Operation::Div;
        r.number = number;
    }

    return str;
}


int main() {
    int number, quantity;
    std::cin >> number >> quantity;

    std::deque<std::string> Deque;
    Deque.push_back(std::to_string(number));

    Request copy_r;
    Request r;

    for (int i = 0; i < quantity; i++) {
        std::cin >> r;

        switch (r.operation) {
            case Operation::Add:
                Deque.emplace_back(" + ");
                Deque.push_back(r.number);
                copy_r = r;
                break;

            case Operation::Sub:
                Deque.emplace_back(" - ");
                Deque.push_back(r.number);
                copy_r = r;
                break;

            case Operation::Mul:
                if (copy_r.operation == Operation::Add || copy_r.operation == Operation::Sub) {
                    Deque.emplace_back(")");
                    Deque.emplace_front("(");
                }

                Deque.emplace_back(" * ");
                Deque.push_back(r.number);
                copy_r = r;
                break;

            case Operation::Div:
                if (copy_r.operation == Operation::Add || copy_r.operation == Operation::Sub) {
                    Deque.emplace_back(")");
                    Deque.emplace_front("(");
                }

                Deque.push_back(" / ");
                Deque.push_back(r.number);
                copy_r = r;
                break;
        }
    }

    for (auto& elem: Deque) {
        std::cout << elem;
    }
    return 0;
}

