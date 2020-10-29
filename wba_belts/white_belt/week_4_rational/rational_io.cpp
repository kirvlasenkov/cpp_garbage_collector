#include <iostream>
#include <sstream>
#include <numeric>


using namespace std;


class Rational {
public:

    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        int greatest = gcd(new_denominator, new_numerator);

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
/* Rational operator+(const Rational &lhs, const Rational &rhs) {
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
} */
