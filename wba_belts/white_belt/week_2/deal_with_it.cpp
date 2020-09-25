#include <iostream>
#include <vector>
#include <string>



int main()
{
	//initialize
	int day_num;																	// номер дня
	std::string deal, command; 														// дело 
	std::vector<int> month_num = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // кол-во дней в каждом месяце
	int current_month = 0;															// текущие дни
	std::vector<std::vector<std::string>> current_deals(month_num[current_month]);  // вектор из векторов, где каждый подвектор 
	int number_of_commands;															// отвечает за наименование дел в дне

	std::cin >> number_of_commands;

	for (int k = 0; k < number_of_commands; k++) {

		std::cin >> command;

		if (command == "ADD") {

			std::cin >> day_num >> deal;

			current_deals[day_num].push_back(deal);

		}

		else if (command == "DUMP") {
			
			std::cin >> day_num;

			std::cout << current_deals[day_num].size() << " ";
			
			for (auto deals: current_deals[day_num]) {

				std::cout << deals << " ";
			
			}

		}

		else if (command == "NEXT") { 

			int quant_old_month = month_num[current_month];

			current_month++;

			if (current_month % 12 == 0) { 
				
				current_month = 0;

			}

			int quant_new_month = month_num[current_month];

			if (quant_new_month >= quant_old_month) {

				current_deals.resize(quant_new_month);

			} else {

				 for(int j = quant_new_month; j < quant_old_month; j++){
                    deals_in_month.insert(end(deals_in_month), begin(month_deals[j]), end(month_deals[j]));
                }

				current_deals.resize(quant_new_month);
			}


		}
	}



	return 0;
}