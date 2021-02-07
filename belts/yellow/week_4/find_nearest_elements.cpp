#include <iostream>
#include <algorithm>
#include <set>


std::set<int>::const_iterator FindNearestElement(
        const std::set<int>& numbers,
        int border);
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел


std::set<int>::const_iterator FindNearestElement( const std::set<int>& numbers, int border) {
    const auto it = numbers.lower_bound(border);

    if (*it == border || it == numbers.begin()) {
        return it;
    }
    const auto minused_it =  std::prev(it);
    if (std::abs(*minused_it - border) <= std::abs(*it - border)) {
        return minused_it;
    }
    return it;
}

/*
int main() {
    std::set<int> numbers = {1, 4, 6};
    std::cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << std::endl;

    std::set<int> empty_set;

    std::cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << std::endl;
    return 0;
}
 */