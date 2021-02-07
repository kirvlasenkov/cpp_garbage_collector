#include <iostream>
#include <vector>
#include <string>



int summarize(std::vector<bool>& lst)
{
	int sum = 0;

	for (auto num: lst) {
		sum += num;
	}

	return sum;
}


int main()
{	

	int number_of_comm;
	int i;
	std::string command;
	std::vector<bool> queue;

	std::cin >> number_of_comm;

	// true означает, что человек беспокоится;
	// false то, что он спокоен;
	
	for (int j = 0; j < number_of_comm; j++) {

		std::cin >> command;  

		if (command == "WORRY") {
			std::cin >> i;
			queue[i] = true;
		}

		else if (command == "QUIET") {
			std::cin >> i;
			queue[i] = false;
		}
 
		else if (command == "COME") {
			std::cin >> i;
			queue.resize(queue.size() + i, false);
		}

		else if (command == "WORRY_COUNT") {
			 std::cout << summarize(queue) << std::endl;
		}
	}

	return 0;

}