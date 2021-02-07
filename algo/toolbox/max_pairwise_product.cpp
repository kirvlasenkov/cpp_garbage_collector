#include <iostream>
#include <vector>


long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_first = 0;
    long long max_second = 0;

    int n = numbers.size();

    for (size_t i = 0; i < n; i++) {
        if ((long long)numbers[i] > max_first) {
            max_second = max_first;
            max_first = numbers[i];
        }

        else if ((long long)numbers[i] <= max_first and (long long)numbers[i] > max_second) {
            max_second = numbers[i];
        }
    }

    return max_first * max_second;

}
/*
int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
*/