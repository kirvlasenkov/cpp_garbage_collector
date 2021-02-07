#include <iostream>

#define MOD 10


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long get_array_sum_(const long long *array, unsigned len) {
    long long sum = 0;

    for (size_t i = 0; i < len; i++) {
        sum += array[i];
    }

    return sum % 10;
}


long long get_sum_before(const long long *array, unsigned number) {
    long long sum = 0;

    for (size_t i = 0; i <= number; i++) {
        sum += array[i];
    }

    return sum % 10;
}

long long get_sum_after(const long long *array, unsigned number, long long array_len) {
    long long sum = 0;

    for (size_t i = number; i <= array_len; i++) {
        sum += array[i];
    }

    return sum % 10;
}



long long make_pizano_loop_(long long *pizano_row) { // makes pizano loop from the given array and returns length of pizano loop
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

    return i - 1; // returns length of pizano loop
}


long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long pizano_row[MOD * MOD];
    long long loop_len = make_pizano_loop_(pizano_row);
    long long sum_before_remained_to = get_sum_before(pizano_row, to % loop_len);
    long long sum_after_remained_from = get_sum_after(pizano_row, from % loop_len, loop_len);
    long long loop_sum = get_array_sum_(pizano_row, loop_len);

    if ((to - from - (to % loop_len) - (from % loop_len) > loop_len)) {
        return (sum_before_remained_to + (loop_sum * (to - from - (to % loop_len) - (from % loop_len) > loop_len) / loop_len) + sum_after_remained_from) % 10;
    }
    else {
        return (sum_after_remained_from + sum_before_remained_to) % 10;
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
