#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;


template<typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt begin, RandomIt  end, char prefix) {

    std::string str_prefix_1 = {prefix};
    auto prefix_start = std::lower_bound(begin, end, str_prefix_1);

    char next_prefix = static_cast<char>(prefix + 1);
    std::string str_prefix_2 = {next_prefix};
    auto prefix_finish = std::upper_bound(begin, end, str_prefix_2);

    return std::make_pair(prefix_start, prefix_finish);

}
/*
int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}
 */