#include <iostream>
#include <map>
#include <string>



std::map<char, int> BuildCharCounters(const std::string& line)
{
	std::map<char, int> result;

	for (const auto& letter : line) {

			result[letter]++;
	
	}

	return result;

}

void PrintMap(std::map<char, int> mapper)
{
	for (const auto& [key, value] : mapper) {

		std::cout << key << value << std::endl;
	
	}

}

int main()
{
	int N;

	std::string word_1, word_2;

	std::cin >> N;

	for (int i = 0; i < N; i++) {

		
		std::cin >> word_1 >> word_2;

		if (BuildCharCounters(word_1) == BuildCharCounters(word_2)) {

			std::cout << "YES" << std::endl;

		} else {

			std::cout << "NO" << std::endl;
		
		}
	
	}

	return 0;
}