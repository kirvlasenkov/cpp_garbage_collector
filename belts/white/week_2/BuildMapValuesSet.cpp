#include <iostream>
#include <map>
#include <set>
#include <string>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& dict)
{
	std::set<std::string> result;	

	for (const auto& items : dict) {

		result.insert(items.second);
	}

	return result;
}

int main()
{
	return 0;
}