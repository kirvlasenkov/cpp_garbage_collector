#include <iostream>
#include <deque>

/*
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

std::istream &operator>>(std::istream &str, Request &r) {
    std::string sign;
    std::string number;
    str >> sign >> number;

    if (sign == "+") {
        r.operation = Operation::Add;
        r.number = number;
    } else if (sign == "-") {
        r.operation = Operation::Sub;
        r.number = number;
    } else if (sign == "*") {
        r.operation = Operation::Mul;
        r.number = number;
    } else if (sign == "/") {
        r.operation = Operation::Div;
        r.number = number;
    }

    return str;
}


int main() {
    int number, quantity;
    std::cin >> number >> quantity;

    std::deque<std::string> Deque;
    Request r;

    Deque.push_back(std::to_string(number));

    for (int i = 0; i < quantity; i++) {
        std::cin >> r;
        switch (r.operation) {
            case Operation::Add:
                Deque.push_front("(");
                Deque.push_back(")");
                Deque.push_back(" + ");
                Deque.push_back(r.number);
                break;

            case Operation::Sub:
                Deque.push_front("(");
                Deque.push_back(")");
                Deque.push_back(" - ");
                Deque.push_back(r.number);
                break;

            case Operation::Mul:
                Deque.push_front("(");
                Deque.push_back(")");
                Deque.push_back(" * ");
                Deque.push_back(r.number);
                break;

            case Operation::Div:
                Deque.push_front("(");
                Deque.push_back(")");
                Deque.push_back(" / ");
                Deque.push_back(r.number);
                break;
        }
    }

    for (const auto& item : Deque) {
        std::cout << item;
    }

    return 0;
}
 */