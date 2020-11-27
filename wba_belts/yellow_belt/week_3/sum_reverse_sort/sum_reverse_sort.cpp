#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
    return x + y;
}

std::string Reverse(std::string s)
{
    int size = s.size(), temp;
    for (int i = 0; i < size/2; i++) {
        temp = s[i];
        s[i] = s[size-1-i];
        s[size-1-i] = temp;
    }
    return s;
};

void Sort(std::vector<int> &v) {
    std::sort(v.begin(), v.end());
}
