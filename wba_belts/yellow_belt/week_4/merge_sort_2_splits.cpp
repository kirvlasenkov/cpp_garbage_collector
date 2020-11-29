#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

/*
template<typename RandomIt>
void MergeSort(RandomIt begin, RandomIt end) {
    if (end - begin < 2) {
        return;
    }

    std::vector<typename RandomIt::value_type> elements(begin, end);

    auto middle = elements.begin() + (elements.end() - elements.begin()) / 2;
    MergeSort(elements.begin(), middle);
    MergeSort(middle, elements.end());
    std::merge(elements.begin(), middle, middle, elements.end(), begin);

}


int main() {
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/