#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>


std::string create_seq(std::vector<std::string> words)
{
	std::string answer = "(";
	for (int i=1; i < words.size() - 1; i++) {

		answer += (words[i] + ", ");
	}

	answer += words[words.size() - 1] + ")";

	return answer;
}


class Person
{
	
	public:
		
		Person() {}
		Person (std::string first_name,
		 		std::string last_name,
		 		int year ) {

			date_of_birth = year;
			first_name_history[year] = first_name;
			last_name_history[year] = last_name;
		}

		void ChangeFirstName(int year, const std::string& first_name) {
			if (!(year < date_of_birth )) {
			    first_name_history[year] = first_name;
			
			}
	    }
		
		void ChangeLastName(int year, const std::string& last_name) {
	    	if (!(year < date_of_birth ))
	    	    last_name_history[year] = last_name;
	  	}

	  	std::string GetFullName(int year) {
	  		if ((year < date_of_birth )) {
	  			return "No person";
	  		}

	  		std::string current_first_name = "";
	  		std::string current_last_name = "";
	  		std::string output = "";
	  		int current_year = 0;

			for (const auto& items: first_name_history) {

		    	if (items.first <= year && items.first >= current_year) {

		    		current_year = items.first;
		    		current_first_name = items.second;	
				}
		    }

		    current_year = 0;
		    for (const auto& items: last_name_history) {

		    	if (items.first <= year && items.first >= current_year) {

		    		current_year = items.first;
		    		current_last_name = items.second;	
				}
		    }


		    if (current_last_name.length() == 0 &&
		    	current_first_name.length()== 0) {

		    	output = "Incognito";
		    
		    }  else if (current_last_name.length() != 0 &&
		    	current_first_name.length() != 0) {

		    	output =  current_first_name + " " + current_last_name;
		    
		    }  else if (current_last_name.length() == 0 &&
		    	current_first_name.length() != 0) {

		    	output = current_first_name + " with unknown last name";
		    
		    }  else if (current_last_name.length() != 0 &&
		    	current_first_name.length()== 0) {

		    	output =  current_last_name + " with unknown first name";
		    }


	  	
		    return output;
	  	}


	  	std::string GetFullNameWithHistory(int year) {
	  		if ((year < date_of_birth )) {
	  			return "No person";
	  		}

	  		std::vector<std::string> all_first_to_year;
	  		std::vector<std::string> all_last_to_year;
	  		std::string last_added_first;
	  		std::string last_added_last;
	  		std::string output;

	  		for (const auto& items: first_name_history) {

		    	if (items.first <= year &&
		    		 items.second != last_added_first) {


		    		all_first_to_year.push_back(items.second);
					last_added_first = items.second;
				}
		    }


	  		for (const auto& items: last_name_history) {

		    	if (items.first <= year &&
		    		 items.second != last_added_last) {


		    		all_last_to_year.push_back(items.second);
					last_added_last = items.second;
				}
		    }

		    std::string correct_first;
		    std::string correct_last;


		    if (all_first_to_year.size() > 1)
		    	std::reverse(all_first_to_year.begin(), all_first_to_year.end());
		    
		    if (all_last_to_year.size() > 1)
		    	std::reverse(all_last_to_year.begin(), all_last_to_year.end());

		    if (all_first_to_year.size() != 0)
		    	correct_first = all_first_to_year.front();
		    
		    if (all_last_to_year.size() != 0)
		    	correct_last = all_last_to_year.front();

		    if (all_first_to_year.size() > 1)
		    	all_first_to_year.erase(all_first_to_year.begin());

		    if (all_last_to_year.size() > 1)
		    	all_last_to_year.erase(all_last_to_year.begin());      


		    // Zone of formated printing
		    if (all_first_to_year.size() == 0 &&
		    	 all_last_to_year.size() == 0) {

		    	output = "Incognito";
		    }

		    else if (all_first_to_year.size() != 0 &&
		    	 all_last_to_year.size() == 0) {

		    	
		    	output = correct_first + " " + 
		    		create_seq(all_first_to_year) + " " +
		    		"with unknown last name";
		    }

		    else if (all_first_to_year.size() == 0 &&
		    	 all_last_to_year.size() != 0) {

		    	output = correct_last + " " + 
		    		create_seq(all_last_to_year) + " " +
		    		"with unknown first name";
		    }

		    else if (all_first_to_year.size() != 0 &&
		    	 all_last_to_year.size() != 0) {

		    	output = correct_first + " " +
		    	create_seq(all_first_to_year) + " " + 
		    	correct_last + " " +
		    	create_seq(all_last_to_year);
		    }

		    return output;


	  	}


	private:
		std::map<int, std::string> first_name_history;
		std::map<int, std::string> last_name_history;
		int date_of_birth;

};

int main() {

 Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  std::cout << person.GetFullNameWithHistory(1990) << std::endl;
  
  person.ChangeFirstName(1966, "Pauline");
  std::cout << person.GetFullNameWithHistory(1966) << std::endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  std::cout << person.GetFullNameWithHistory(1967) << std::endl;
  
  return 0;
}