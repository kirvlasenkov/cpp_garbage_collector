#include <iostream>
#include <map>
#include <vector>

int main()
{
	int number_of_command;

	std::map<std::vector<std::string>, int> BUS_PATH;

	std::cin >> number_of_command;

	for (int i = 0; i < number_of_command; i++) {

		int number_of_stops;

		std::vector<std::string> stop_vector;

		std::cin >> number_of_stops;

		for (int j = 0; j < number_of_stops; j++) {

			std::string stop;

			std::cin >> stop;

			stop_vector.push_back(stop);
		
		}

		if (BUS_PATH.count(stop_vector) == 0) {

			int temp = BUS_PATH.size() + 1;

			BUS_PATH[stop_vector] = temp;

			std::cout << "New bus " << BUS_PATH[stop_vector] << std::endl;
		
		} else {

			std::cout << "Already exists for " << BUS_PATH[stop_vector] << std::endl;
		
		}

		stop_vector.clear();
	
	}
}