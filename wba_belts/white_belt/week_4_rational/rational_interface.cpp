#include <iostream>
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

/* int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "numerator: " << r.Numerator() << " denominator: " << r.Denominator();
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "numerator: " << r.Numerator() << " denominator: " << r.Denominator();
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "numerator: " << r.Numerator() << " denominator: " << r.Denominator();
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "numerator: " << r.Numerator() << " denominator: " << r.Denominator();
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "numerator: " << r.Numerator() << " denominator: " << r.Denominator();
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
} */