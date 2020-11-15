#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <cassert>


void Func(std::vector<int>  &v) {
    v.push_back(2);
}

void  TestFunc() {

    std::vector<int> v{2, 3, 4};
    Func(v);
    std::vector<int> expected {2, 3, 4};
    assert(v ==  expected);
    std::cout << "OK";
}

/* int main()
{
    std::map<int, int> empty;
    std::string empty_string;

    for (const auto &items : empty) {
        std::cout << items.first << " " <<  items.second;
    }

    std::cout << empty_string;
    TestFunc();
    return 0;
}
*/