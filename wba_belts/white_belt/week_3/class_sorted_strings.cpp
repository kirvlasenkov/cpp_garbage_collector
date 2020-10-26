#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class SortedStrings
{
	public:

		void AddString(const std::string& s) {

			string_package.push_back(s);
		}

		std::vector<std::string> GetSortedStrings() {

			sort(begin(string_package), end(string_package));

			return string_package;
		}

	private:

		std::vector<std::string> string_package;

};