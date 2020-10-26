#include <iostream>
#include <set>
#include <string>

int main()
{

	int number_of_words;
	std::set<std::string> set_of_words;

	std::cin >> number_of_words;

	for (int i = 0; i < number_of_words; i++) {

		std::string word;

		std::cin >> word;

		set_of_words.insert(word);
	
	}

	std::cout << set_of_words.size() << std::endl;

	return 0;
}