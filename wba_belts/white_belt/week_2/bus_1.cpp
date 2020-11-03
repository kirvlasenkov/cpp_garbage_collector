#include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{	
	// bus - название маршрута; stop - название остановки

	std::map<std::string, std::vector<std::string>> BUS_BOOK; // отображение bus -> stop

	std::map<std::string, std::vector<std::string>> STOP_BOOK; // отображение stop -> bus

	int number_of_command;

	std::cin >> number_of_command;

	for (int i = 0; i < number_of_command; i++) {

		std::string command;

		std::cin >> command;

		if (command == "NEW_BUS") { // создание нового маршрута

			std::string bus;

			int stop_count;

			std::cin >> bus >> stop_count;

			for (int i = 0; i < stop_count; ++i) {

				std::string stop;

				std::cin >> stop;

				BUS_BOOK[bus].push_back(stop);

				STOP_BOOK[stop].push_back(bus);


			} 


			
		}
		

		else if (command == "BUSES_FOR_STOP") {

			std::string stop;

			std::cin >> stop;

			if (STOP_BOOK.count(stop) == 0) {

				std::cout << "No stop" << std::endl;

			} else {

				for (const auto& bus : STOP_BOOK[stop]) {

					std::cout << bus << " ";
				}

				std::cout << std::endl;
			
			}
		

		}

		else if (command == "STOPS_FOR_BUS") {

			std::string bus;

			std::cin >> bus;

			 if (BUS_BOOK.count(bus) == 0) std::cout << "No bus " << std::endl;

			 else{ 

                for (const auto& item : BUS_BOOK[bus]) {

                    std::cout << "Stop " << item << ": ";

                    if (STOP_BOOK.count(item) == 0) std::cout << "no interchange";

                    for (const auto& stop : STOP_BOOK[item]){

                        if ((bus == stop) && (STOP_BOOK[item].size() == 1))  std::cout << "no interchange";
                        
                        else if (bus == stop);

                        else std::cout << stop << " ";
                    
                    }

                    std::cout << std::endl;
                }
            }

		}

		else if (command == "ALL_BUSES") {

			if (BUS_BOOK.size() == 0) {

				std::cout << "No buses" << std::endl;
			
			} 

			for (const auto& items : BUS_BOOK) {

				std::cout << "Bus " << items.first << ": ";

				for (const auto& stops : items.second) {

                std::cout << stops << " ";
				
				}

			std::cout << std::endl;
			
			}


		}

	
	}

	return 0;

}