#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_last_digit(int n) {
    int fibo_row[n];
    fibo_row[0] = 0;
    fibo_row[1] = 1;

    for (size_t i = 2; i <= n; i++) {
        fibo_row[i] = (fibo_row[i - 1] + fibo_row[i - 2]) % 10;
    }

    return fibo_row[n];
}

/*
int main() {
    int n;
    std::cin >> n;
    int c = fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
*/