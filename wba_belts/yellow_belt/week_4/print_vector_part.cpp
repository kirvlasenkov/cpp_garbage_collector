#include <iostream>
#include <vector>
#include <algorithm>

void PrintVectorPart(const std::vector<int> &numbers) {
    auto negative_it = std::find_if(
            numbers.begin(), numbers.end(),
            [](int number) {
                return number < 0;
            }
    );

    for (auto i = negative_it ; i > numbers.begin();) {
        std::cout << *(--i) << " ";
    }
    std::cout << std::endl;
}
/*
int main() {
    PrintVectorPart({6, 1, 8, 5, 4});
    return 0;
}*/