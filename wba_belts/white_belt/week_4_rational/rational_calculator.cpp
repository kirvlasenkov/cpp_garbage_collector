#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

class Rational {
public:

    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        int greatest = gcd(new_denominator, new_numerator);

        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }

        if (greatest != 0) {
            new_denominator /= greatest;
            new_numerator /= greatest;
        }

        if (new_denominator * new_numerator >= 0) {
            if (new_denominator >= 0) {
                numerator = new_numerator;
                denominator = new_denominator;
            } else {
                numerator = -new_numerator;
                denominator = -new_denominator;
            }
        } else {
            if (new_denominator < 0) {
                numerator = -new_numerator;
                denominator = -new_denominator;
            } else {
                numerator = new_numerator;
                denominator = new_denominator;

            }

        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:

    int numerator;
    int denominator;
};

// перегрузка операторов сравения, суммирования и вычитания, умножения и деления, а также потоки in и out
Rational operator+(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator());

}

bool operator==(const Rational &lhs, const Rational &rhs) {

    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0) {
        throw invalid_argument("Division by zero");
    }
    return {lhs.Numerator() * rhs.Denominator(),
            lhs.Denominator() * rhs.Numerator()};
}

ostream& operator<<(ostream& output, const Rational& fraction) {
    output << fraction.Numerator() <<"/" << fraction.Denominator();
    return output;
}

istream& operator>>(istream& input, Rational& fraction) {
    if (input) {
        int numer, denom = 0;
        char oper;
        input >> numer;
        input >> oper;
        input >> denom;
        if (oper =='/')
            if (denom != 0)
                fraction = {numer, denom};
    }
    return input;
}


bool operator < (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
}

Rational ReadFraction(istream& stream) {
    int lhs, rhs;
    char operation;

    stream >> lhs;
    if (stream.peek() != '/') {
        throw domain_error("invalid symbol of fraction");
    }
    stream.ignore(1);
    stream >> rhs;

    return {lhs, rhs};
}


int main()
{
    set<char> symbols = {'+', '-', '/', '*'};
    try {

        Rational fraction_1 = ReadFraction(cin);
        char oper;
        cin >> oper;
        if (bool checker = symbols.find(oper) == symbols.end()) {
            throw runtime_error("wrong symbol");
        }
        Rational fraction_2 = ReadFraction(cin);

        if (oper == '+') {
            cout << fraction_1 + fraction_2;
        }

        else if (oper == '-') {
            cout << fraction_1 - fraction_2;
        }

        else if (oper == '*') {
            cout << fraction_1 * fraction_2;
        }

        else {
            cout << fraction_1 / fraction_2;
        }

    } catch (const exception& ex) {
        cout << ex.what();
    }

    return 0;
}
