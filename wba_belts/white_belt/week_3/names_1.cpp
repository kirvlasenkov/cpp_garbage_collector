#include <iostream>
#include <map>
#include <vector>
#include <string>


class Person
{
	private:

		std::map<int, std::string> f_name_data;
		std::map<int, std::string> l_name_data;

	public:

		void ChangeFirstName(int year, const std::string& first_name) {
    		
    		f_name_data[year] = first_name;
  		
  		}
  		
  		void ChangeLastName(int year, const std::string& last_name) {
    		
    		l_name_data[year] = last_name;
  		
  		}

  		std::string GetFullName(int year) {
    		
    		if (l_name_data.count(year) == 0 && f_name_data.count(year) == 0) {

    			return "Incognito";
    		}

    		else if (l_name_data.count(year) == 0) {

    			return f_name_data[year] + " with unknown last name";
    		}

    		else if (f_name_data.count(year) == 0) {

    			return l_name_data[year] + " without unknown first name";
    		}

    		else {

    			return f_name_data[year] + " "  + l_name_data[year];
    		}
  		}

};


/*int main() {

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
}*/