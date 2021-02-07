#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


/* int main()
{
	std::ifstream input("input.txt");

	if (input) {

		int N, M;
		int temp;

		input >> N;
		input >> M;

		for (int i = 0; i < N; i++) {
	
			for (int j = 0; j < M; j++) {			
		
				if (j == M - 1) {

					input >> temp;

					std::cout << std::setw(10) << temp;

				} else {
			    	
			    	input >> temp;
			    	input.ignore(1);
			    	std::cout << std::setw(10) <<  temp << " ";
				}
			}

			std::cout << std::endl;
		}

	}

	return 0;
} */
