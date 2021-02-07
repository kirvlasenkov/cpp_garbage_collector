#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


template<typename RandomIt>
void MergeSort(RandomIt begin, RandomIt end) {
    if (end - begin < 2) {
        return;
    }

    std::vector<typename RandomIt::value_type> elements(begin, end);
    std::vector<typename RandomIt::value_type> temp;

    auto first_third = elements.begin() + (elements.end() - elements.begin()) / 3;
    auto second_third = first_third + (elements.end() - elements.begin()) / 3;

    MergeSort(elements.begin(), first_third);
    MergeSort(first_third, second_third);
    MergeSort(second_third, elements.end());

    std::merge(elements.begin(), first_third, first_third, second_third, std::back_inserter(temp));
    std::merge(temp.begin(), temp.end(), second_third, elements.end(), begin);

}
/*
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