#include <iostream>
#include <set>
#include <vector>
#include <string>

template <typename T>
std::vector<T> FindGreaterElements(std::set<T> elements, T border) {
    std::vector<T> ans;

    for (auto it = elements.begin(); it != elements.end(); it++) {
        if (*it > border) {
            ans.push_back(*it);
        }
    }

    return ans;
}

/*
int main() {
    for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::string to_find = "Python";
    std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
    return 0;
} */