#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>


bool module_neq (int a, int b) {return abs(a) < abs(b);}

int main()
{
	int N;

	std::cin >> N;
	std::vector<int> list(N);

	for (auto& elem: list) {

		std::cin >> elem;
	
	}

	sort(begin(list), end(list), module_neq);

	for (const auto& elem : list) {

		std::cout << elem << " ";
	}
	std::cout << std::endl;

	return 0;
}