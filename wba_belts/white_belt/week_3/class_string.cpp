#include <iostream>
#include <string>


class ReversibleString
{
	public:	
	ReversibleString() {}
	ReversibleString(const std::string& line) {

		data = line;

	}

	std::string ToString() const {

		return data;
	}

	void Reverse() {

		for (int i = 0, j = data.length() - 1; i <= j; i++, j--) {

			std::swap(data[i], data[j]);
		}

		
	}

	/* void RealReverse() {
		char tmp;
		char* send = data + data.length() - 1;

		while (send > data ) {
			tmp = *send;
			*send = *data;
			*data = *send;
			data++, send--;

		} */
	

    private:
    	std::string data;


};


int main() {
  ReversibleString s("live");
  s.Reverse();
  std::cout << s.ToString() << std::endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  std::string tmp = s_ref.ToString();
  std::cout << tmp << std::endl;
  
  ReversibleString empty;
  std::cout << '"' << empty.ToString() << '"' << std::endl;
  
  return 0;
}
