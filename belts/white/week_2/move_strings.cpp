#include<iostream>
#include <vector>
#include <string>

using namespace std;

//void MoveStrings(std::vector<std::string> source, std::vector<std::string> destination);

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {
	for (auto word: source) 
		destination.push_back(word);
	source.clear();
}

int main()
{
	std::vector<std::string> source = {"a", "b", "c"};
	std::vector<std::string> destination = {"d", "e"};
	MoveStrings(source, destination);

	for (auto word: destination) 
		cout << "it is source:" << word << " " << endl;
	return 0;
} 


