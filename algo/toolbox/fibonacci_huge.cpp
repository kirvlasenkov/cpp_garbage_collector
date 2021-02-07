#include <iostream>
#include <vector>


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long pizano_row[m * m];
    pizano_row[0] = 0;
    pizano_row[1] = 1;

    long long i = 2;
    while (true) {
       pizano_row[i] = (pizano_row[i - 1] + pizano_row[i - 2]) % m;

       if (pizano_row[i] == 1 && pizano_row[i - 1] == 0 && i > 2)
           break;
        i++;
    }

    long long pizano_len = i - 1;

    return pizano_row[n % pizano_len];
}

/*
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

    return 0;
}
*/