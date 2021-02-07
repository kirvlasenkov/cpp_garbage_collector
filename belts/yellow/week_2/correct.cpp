#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    int request_number;
    std::cin >> request_number;
    std::map<std::string, std::vector<std::string>> bus_to_stop;
    std::map<std::string, std::vector<std::string>> stop_to_bus;

    for (size_t i = 0; i < request_number; i++) {
        std::string request;
        std::cin >> request;

        if (request == "NEW_BUS") {
            std::string bus;
            int stop_count;
            std::cin >> bus >> stop_count;
            for (size_t j = 0; i < stop_count; i++) {
                std::string stop;
                std::cin >> stop;
                bus_to_stop[bus].push_back(stop);
                stop_to_bus[stop].push_back(bus);
            }
        } else if (request == "BUSES_FOR_STOP") {
            std::string stop;
            std::cin >> stop;
            for (auto bus : stop_to_bus[stop]) {
                std::cout << bus << " ";
            }
            std::cout << std::endl;
        } else if (request == "STOPS_FOR_BUSES") {
            std::string bus;
            std::cin >> bus;

            if (bus_to_stop.count(bus) == 0) {
                std::cout << "No bus" << std::endl;
            } else {
                for (auto &stop : bus_to_stop[bus]) {
                    if (stop_to_bus[stop].size() == 1) {
                        std::cout << "no interchange";
                    } else {
                        std::cout << "Stop " + stop + ": ";
                        for (auto &temp_bus : stop_to_bus[stop]) {
                            if (temp_bus != bus) {
                                std::cout << temp_bus << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                }
            }
        } else if (request == "ALL_BUSES") {

            if (bus_to_stop.empty()) {
                std::cout << "No buses" << std::endl;
            } else {
                for (const auto &bus_item : bus_to_stop) {
                    std::cout << "Bus " << bus_item.first << ": ";
                    for (const std::string &stop : bus_item.second) {
                        std::cout << stop << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }

    }
}