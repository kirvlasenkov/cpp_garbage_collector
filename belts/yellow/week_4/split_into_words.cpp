#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>


std::vector<std::string> SplitIntoWords(const std::string &words) {
    std::vector<std::string> ans;
    auto it = std::begin(words);

    while (it < std::end(words)) {
        auto space = std::find(it, std::end(words), ' ');
        ans.push_back({it, space});
        it = ++space;
    }

    return ans;
}
/*
int main() {
    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
*/