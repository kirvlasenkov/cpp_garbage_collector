#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>


// INIT
template <typename T> T Sqr(T);
template<typename T> std::vector<T> operator*(std::vector<T> &lhs, std::vector<T> &rhs);
template<typename first, typename second> std::pair<first, second> operator*(std::pair<first, second> &lhs, std::pair<first, second> &rhs);
template<typename key, typename value> std::map<key, value> operator*(std::map<key, value> &lhs, std::map<key, value> &rhs);


//vector template
template<typename T>
std::vector<T> operator*(std::vector<T> &lhs, std::vector<T> &rhs) {
    for (int i = 0; i < static_cast<int>(lhs.size()); i++) {
        lhs[i] = lhs[i] * rhs[i];
    }

    return lhs;
}


// pair template
template<typename first, typename second>
std::pair<first, second> operator*(std::pair<first, second> &lhs, std::pair<first, second> &rhs) {
    return std::pair<first, second>{lhs.first * rhs.first, lhs.second * rhs.second};
}


//map template
template<typename key, typename value>
std::map<key, value> operator*(std::map<key, value> &lhs, std::map<key, value> &rhs) {
    for (auto &items: lhs) {
        lhs[items.first] = items.second * items.second;
    }
    return lhs;
}


// all-squared template
template<typename T>
T Sqr(T argument) {
    return argument * argument;
}


/* int main() {
    std::vector<int> v = {1, 2, 3};
    std::pair<int, int> p = {1, 100};
    std::pair<int, int> p1 = Sqr(p);
    std::map<std::string, int> mapa{ {"a", 1}, {"b", 2}, {"c", 3} };

    for (const auto &items : Sqr(mapa)) {
        std::cout << items.first << " " << items.second << std::endl;
    }

    std::cout << p1.first << " " << p1.second << std::endl;
    std::cout << "vector:";
    for (auto x : Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }

    return 0;
} */

