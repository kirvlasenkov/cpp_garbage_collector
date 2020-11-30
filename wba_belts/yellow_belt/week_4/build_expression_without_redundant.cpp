#include <iostream>
#include <deque>


enum class Operation {
    Add,
    Sub,
    Mul,
    Div
};

struct Request {
    Operation type;
    std::string value;
};

std::istream& operator >> (std::istream& is, Request& q) {
    std::string str;
    is >> str;
    if (str == "+") {
        q.type = Operation::Add;
        is >> q.value;
    } else if (str == "-") {
        q.type = Operation::Sub;
        is >> q.value;
    } else if (str == "*") {
        q.type = Operation::Mul;
        is >> q.value;
    } else if (str == "/") {
        q.type = Operation::Div;
        is >> q.value;
    }

    return is;
}

int main() {
    int x;
    std::cin >> x;

    int n;
    std::cin >> n;
    Request q;
    Request p;

    std::deque<std::string> Deque;
    Deque.push_back(std::to_string(x));

    for (int i = 0; i < n; ++i) {
        std::cin >> q;
        switch (q.type) {
            case Operation::Add:
                Deque.push_back("+");
                Deque.push_back(q.value);
                p = q;
                break;
            case Operation::Sub:
                Deque.push_back("-");
                Deque.push_back(q.value);
                p = q;
                break;
            case Operation::Mul:
                if (p.type == Operation::Add || p.type == Operation::Sub) {
                    Deque.push_front("(");
                    Deque.push_back(")");
                }
                Deque.push_back("*");
                Deque.push_back(q.value);
                p = q;
                break;
            case Operation::Div:
                if (p.type == Operation::Add || p.type == Operation::Sub) {
                    Deque.push_front("(");
                    Deque.push_back(")");
                }
                Deque.push_back("/");
                Deque.push_back(q.value);
                p = q;
                break;
        }
    }

    for (auto& item : Deque) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            std::cout << " " << item << " ";
        } else {
            std::cout << item;
        }
    }

    return 0;
}