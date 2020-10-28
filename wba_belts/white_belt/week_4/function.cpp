#include <iostream>
#include <vector>
#include <algorithm>

 struct Image {
	double quality;
	double freshness;
	double rating;
};


struct Params {
	double a;
	double b;
	double c;
}; 


class OperatorParts {

public:

	OperatorParts(char new_operator,
				  double new_value) {

		operation = new_operator;
		value = new_value;
	}

	double Apply(double sum_value) const {
		if (operation == '+') {

			sum_value += value;
			return sum_value;
		
		} else if (operation == '-') {

			sum_value -= value;
			return sum_value;
		
		} else if (operation == '*') {

			sum_value *= value;
			return sum_value;
		
		} else {

			sum_value /= value;
			return sum_value;
		} 
	}

	void Invert() {
		if (operation == '+') {
			
			operation = '-';
		
		} else if (operation == '-') {

			operation = '+';
		
		} else if (operation == '*') {

			operation = '/';
		
		} else {

			operation = '*';

		}

	}

private:

	 char operation;
	 double value;

};

class Function {
public:
	void AddPart(char operation, double value) {
		parts.push_back({operation, value});

	}

	double Apply(double value) const {

		for (const auto& oper: parts) {

			value = oper.Apply(value);
		}

		return value;
	}

	void Invert() {

		for (auto& oper: parts) {

			oper.Invert();
		}

		reverse(begin(parts), end(parts));
	}

private:
	std::vector<OperatorParts> parts;
};


 Function MakeWeightFunction(const Params& param,
							const Image& image) {

	Function function;
	function.AddPart('-', image.freshness * param.a + param.b);
	function.AddPart('+', image.rating * param.c);
	
	return function;
}


double ComputeImageWeight(const Params& params, 
			              const Image& image) {

  Function function = MakeWeightFunction(params, image);
  
  return function.Apply(image.quality);
}


double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {

  Function function = MakeWeightFunction(params, image);
  function.Invert();
  
  return function.Apply(weight);
}



/*int main()
{
	std::cout << "Hello world!" << std::endl;
	return 0;
} */