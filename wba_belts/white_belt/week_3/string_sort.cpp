#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool string_comparison(std::string line_1, std::string line_2) {

	for (auto& letter: line_1) {
		letter = tolower(letter);
	}

	for (auto& letter: line_2) {
		letter = tolower(letter);
	}

	return line_1 < line_2;
}

int main()
{
	int N;

	std::cin >> N;
	std::vector<std::string> list(N);

	for (auto& elem: list) {

		std::cin >> elem;
	
	}

	sort(begin(list), end(list), string_comparison);

	for (const auto& elem : list) {

		std::cout << elem << " ";
	}
	
	std::cout << std::endl;

	return 0;
}