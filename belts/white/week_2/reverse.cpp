#include<iostream>
#include <vector>
#include <string>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void reverse(vector<int>& numbers) {
	int i = 0, j = numbers.size() - 1;
	while (i <= j) {
		swap(numbers[i], numbers[j]);
		i++, j--;
	}
}

 int main()
{
	vector<int> nums = {1, 2, 3, 4, 5 ,6};
	reverse(nums);
	for (auto n: nums)
		cout << n << " "; 
	return 0;
}