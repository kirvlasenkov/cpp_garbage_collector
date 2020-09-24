#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int> seq) {
	vector<int> res;
	for (int i = seq.size() -1; i >= 0; --i)
		res.push_back(seq[i]);
	return res;
}

int main()
{
	vector<int> nums = {1, 2 ,3 , 4, 5};
	vector<int> lst = Reversed(nums);
	for (auto x: lst)
		cout << x << " ";
	return 0;
} 