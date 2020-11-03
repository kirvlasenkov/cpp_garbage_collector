#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
	int number_of_command;

	std::map<std::set<std::string>, int> BUS_PATH;

	std::cin >> number_of_command;

	for (int i = 0; i < number_of_command; i++) {

		int number_of_stops;

		std::set<std::string> stop_vector;

		std::cin >> number_of_stops;

		for (int j = 0; j < number_of_stops; j++) {

			std::string stop;

			std::cin >> stop;

			stop_vector.insert(stop);
		
		}

		if (count(begin(BUS_PATH), end(BUS_PATH), stop_vector)  == 0) {

			int temp = BUS_PATH.size() + 1;

			BUS_PATH[stop_vector] = temp;

			std::cout << "New bus " << BUS_PATH[stop_vector] << std::endl;
		
		} else {

			std::cout << "Already exists for " << BUS_PATH[stop_vector] << std::endl;
		
		}

		stop_vector.clear();
	
	}
}