#include <iostream>
#include <map>
#include <string>
#include <set>

int main()
{
	int number_of_command;
	std::map<std::string, std::set<std::string>> SYNO_DICT;

	std::cin >> number_of_command;


	for (int i = 0; i < number_of_command; i++) {

		std::string command;
		std::cin >> command;

		if (command == "ADD") {

			std::string word_1, word_2;
			std::cin >> word_1 >> word_2;

			SYNO_DICT[word_1].insert(word_2);
			SYNO_DICT[word_2].insert(word_1);


		}


		if (command == "COUNT") {

			std::string word;
			std::cin >> word;

			std::cout << SYNO_DICT[word].size() << std::endl;

		}


		if (command == "CHECK") {

			std::string word_1, word_2;
			std::cin >> word_1 >> word_2;

			if (SYNO_DICT[word_1].count(word_2) == 1 && 
			 SYNO_DICT[word_2].count(word_1) == 1) {

				std::cout << "YES" << std::endl;
			} else {

				std::cout << "NO" << std::endl;
			}
		
		}
	}

	return 0;
}