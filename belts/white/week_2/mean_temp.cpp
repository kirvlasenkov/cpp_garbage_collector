#include <iostream>
#include <vector>

int main()
{
	int N, sum = 0, mean = 0;
	std::vector<int> answer;

	std::cin >> N;

	std::vector<int> temperatures(N);

	for (int temp&: temperatures) {
		std::cin >> temp;
		sum += temp;
	}

	mean = sum / N;



	for (int i = 0; i <= N - 1; i++) {
		if (temperatures[i] > mean) {
			answer.push_back(i);
		}
	}

	// output
	std::cout << answer.size() << std::endl;
	for (auto num: answer) {
		std::cout << num << " ";
	}

	return 0;	

}