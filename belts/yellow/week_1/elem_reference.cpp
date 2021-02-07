#include <iostream>
#include <map>
#include <string>


// template<typename key, typename value> value &GetRefStrict(std::map<key, value> &collection, int K);

template<typename key, typename value>
value &GetRefStrict(std::map<key, value> &collection, key K) {

    try {
        return collection.at(K);
    } catch (std::exception &error) {
        throw std::runtime_error("");
    }

}

int main() {
    std::map<int, std::string> m = {{0, "value"}};
    std::string &item = GetRefStrict(m, 0);
    item = "newvalue";
    std::cout << m[0] << std::endl; // выведет newvalue
    return 0;
}
