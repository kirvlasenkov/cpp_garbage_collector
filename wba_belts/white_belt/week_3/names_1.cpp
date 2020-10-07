#include <iostream>
#include <vector>
#include <string>
#include <map>


class Person
{
	
	public:
		void ChangeFirstName(int year, const std::string& first_name) {

			first_name_history[year] = first_name;
	    }
		
		void ChangeLastName(int year, const std::string& last_name) {
	    	
	    	last_name_history[year] = last_name;
	  	}

	  	std::string GetFullName(int year) {

	  		std::string current_first_name = "", current_last_name = "", output = "";
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

	private:
		std::map<int, std::string> first_name_history;
		std::map<int, std::string> last_name_history;

};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  return 0;
}