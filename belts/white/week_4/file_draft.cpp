#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


/* int main() {
    const std::string file_name = "file.txt";

    std::ifstream input(file_name);

    if (input) {
        std::string line;

        std::cout << "everything is ok!\n";
        while (getline(input, line)) {
            std::cout << std::setw(3) << std::setfill('.');
            std::cout << line << '\n';

        }

        std::ofstream output(file_name, std::ios::app);

        output << "hello" << std::endl;

    } else {

        std::cout << "error\n";

    }

    return 0;

} */