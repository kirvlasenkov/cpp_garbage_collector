#include <iostream>


#define MOD 10


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_array_sum(const long long *array, unsigned len) {
    long long sum = 0;

    for (size_t i = 0; i < len; i++) {
        sum += array[i];
    }

    return sum % 10;
 }

long long get_remain_sum(const long long *array, unsigned remain_number) {
    long long sum = 0;

    for (size_t i = 0; i <= remain_number; i++) {
        sum += array[i];
    }

    return sum % 10;
}


long long make_pizano_loop(long long *pizano_row) {
    if (!pizano_row)
        return -1;

    pizano_row[0] = 0;
    pizano_row[1] = 1;
    long long i = 2;

    while (true) {
        pizano_row[i] = (pizano_row[i - 1] + pizano_row[i - 2]) % MOD;

        if (pizano_row[i] == 1 && pizano_row[i - 1] == 0 && i > 2)
            break;
        i++;
    }

    return i - 1;
}


int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return static_cast<int>(n);

    long long loop[MOD * MOD];
    long long loop_len = make_pizano_loop(loop);
    long long loop_sum = get_array_sum(loop, loop_len);

    long long loops_quantity = n / loop_len;
    long long remainder_number = n % loop_len;


    return (loop_sum) * loops_quantity + get_remain_sum(loop, remainder_number);

}
/*
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << std::endl;

    return 0;
}
*/