#include "sum_reverse_sort.h"
#include "test_runner.h"

void TestSum() {
    AssertEqual(Sum(1, 1), 2, "1");
    AssertEqual(Sum(0, -1), -1, "2");
    AssertEqual(Sum(0, 0), 0, "3");
}

void TestReverse() {
    AssertEqual(Reverse("abba"), "abba");
    AssertEqual(Reverse("kill"), "llik");
    AssertEqual(Reverse(""), "");
    AssertEqual(Reverse("s"), "s");
}

void TestSort() {
    std::vector<int> v_1 = {1, 2, 1, 4, 1, 3, 42, 3, 1, 22, 12 ,23};
    std::vector<int> v_2 = {1, 2, 1, 4, 1, 3, 42, 3, 1, 22, 12 ,23};
    std::sort(v_1.begin(), v_1.end());
    Sort(v_2);
    for (int i = 0; i < v_1.size(); i++) {
        AssertEqual(v_1[i], v_2[i]);
    }

}
/*
int main() {
    TestRunner runner;
    runner.RunTest(TestSum, "sum");
    runner.RunTest(TestReverse, "reverse");
    runner.RunTest(TestSort, "sort");

}*/