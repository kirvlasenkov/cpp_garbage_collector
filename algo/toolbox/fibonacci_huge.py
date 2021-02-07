# Uses python3
import sys


def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m


def get_fibonacci_huge_fast(n, m):
    if n <= 1:
        return n

    pizano_row = list()
    pizano_row.append(0)
    pizano_row.append(1)

    i = 2
    while True:
        pizano_row.append((pizano_row[i - 1] + pizano_row[i - 2]) % m)

        if pizano_row[i] == 1 and pizano_row[i - 1] == 0 and i != 2:
            break
        i += 1

    return pizano_row[n % (i - 1)]


if __name__ == '__main__':
    n, m = map(int, input().split())
    print(get_fibonacci_huge_fast(n, m))
