#include <iostream>
#include <algorithm>
#include <vector>


template<typename Container>
void PrintContainer(Container c) {
    for (auto elem : c) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void PrintReversedPermutations(int n) {
    std::vector<int> interval;

    for (int i = n; i >= 1; --i) {
        interval.push_back(i);
    }

    do {
        PrintContainer(interval);
    } while (std::prev_permutation(interval.begin(), interval.end()));

    std::cout << std::endl;
}

/*
int main() {
    int n;
    std::cin >> n;
    PrintReversedPermutations(n);

    return 0;
}
*/
