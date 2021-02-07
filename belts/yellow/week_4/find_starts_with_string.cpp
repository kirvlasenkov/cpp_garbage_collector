#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iterator>


template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt begin, RandomIt  end, const std::string& str) {

    auto string_start = std::lower_bound(begin, end, str);

    std::string new_str;
    std::copy(str.begin(), str.end(), std::back_inserter(new_str));
    auto it_to_end = std::prev(new_str.end());
    *it_to_end = static_cast<char>(*it_to_end + 1);

    auto string_finish = std::upper_bound(begin, end, new_str);

    return std::make_pair(string_start, string_finish);

}

/*
int main() {
    const std::vector<std::string> sorted_strings = {};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << std::endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    std::cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << std::endl;

    return 0;
}
*/