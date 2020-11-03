#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <exception>


class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    explicit Date(int new_year, int new_month, int new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }

    // getter block
    int GetYear() const { return year; }

    int GetMonth() const { return month; }

    int GetDay() const { return day; }


private:
    int year;
    int month;
    int day;
};


bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else {
        if (lhs.GetMonth() != rhs.GetMonth()) {
            return lhs.GetMonth() < rhs.GetMonth();
        } else {
            if (lhs.GetDay() < rhs.GetDay()) {
                return true;
            } else {
                return false;
            }
        }
    }
}


void NextIsDash(std::istream &stream) {
    if (stream.peek() != '-') {
        throw std::exception();
    }
    stream.ignore(1);
}

std::ostream &operator<<(std::ostream &stream, const Date &date) { // out operator realization
    stream << std::setfill('0');
    stream << std::setw(4) << date.GetYear() << "-"
           << std::setw(2) << date.GetMonth() << "-"
           << std::setw(2) << date.GetDay();
    return stream;
}

std::istream &operator>>(std::istream &stream, Date &date) { // in operator realization
    std::string str_line;
    stream >> str_line;
    std::stringstream string_stream(str_line);
    int new_year, new_month, new_day;

    try {

        string_stream >> new_year;
        NextIsDash(string_stream);
        string_stream >> new_month;
        NextIsDash(string_stream);
        string_stream >> new_day;

    } catch (std::exception &ex) {
        throw std::exception();
    }
    date = Date{new_year, new_month, new_day};
    return stream;
}

class Database {
public:
    void AddEvent(const Date &date, const std::string &event) {
        if (MAIN_STORAGE.find(date) == MAIN_STORAGE.end()) { // checking existing of the date
            MAIN_STORAGE[date].insert(event);
        } else {
            if (MAIN_STORAGE.at(date).count(event) == 0) { // if there was not same event
                MAIN_STORAGE.at(date).insert(event);
            }
        }
    };

    std::string DelEvent(const Date &date, const std::string &event) {
        if (MAIN_STORAGE.count(date) == 0) { // if date doesn't exist <==> false
            return "Event not found";
        } else {
            if (MAIN_STORAGE.at(date).count(event) == 0) { // if event doesn't exist <==> false
                return "Event not found";
            } else { //else true
                MAIN_STORAGE.at(date).erase(event);
                return "Deleted successfully";
            }
        }
    }

    std::string DelDate(const Date &date) {
        if (MAIN_STORAGE.count(date) == 0) {
            return "Deleted 0 events";
        } else {
            int quantity = size(MAIN_STORAGE.at(date));
            MAIN_STORAGE.erase(date);
            return "Deleted " + std::to_string(quantity) + " events";
        }
    }

    void FindDate(const Date &date) const { // prints the events for a certain date each in a new line
        for (auto &event: MAIN_STORAGE.at(date)) {
            std::cout << event << std::endl;
        }
    }


    void Print() const {
        for (auto &item: MAIN_STORAGE) { // prints all data from table
            for (auto &event: item.second) {
                std::cout << item.first << " " << event << std::endl;
            }
        }
    }

private:
    std::map<Date, std::set<std::string>> MAIN_STORAGE;
};

int main() {
    Database db;

    std::string command;
    while (getline(std::cin, command)) {
        try {
            std::string command_name;
            std::stringstream stream(command);
            stream >> command_name;

            if (command_name == "Add") {
                stream.ignore(1);
                Date date;
                std::string event;
                stream >> date;
                stream.ignore(1);
                stream >> event;
                std::cout << date << "  " << event;

            } else if (command_name == "Del") {
                stream.ignore(1);
                Date date;
                std::string event;
                stream >> date;
                if (stream.peek() == EOF) {
                    std::cout << "without event";
                } else {
                    std::cout << "with event";
                }

            } else if (command_name == "Find") {
                ;

            } else if (command_name == "Print") {
                ;
            }

        } catch (std::exception &ex) {
            std::cout << "error";
        }

    }


    db.AddEvent(Date{2009, 19, 11}, "grg");
    db.AddEvent(Date{2009, 19, 11}, "arer");
    db.AddEvent(Date{2009, 19, 11}, "aafvwev");
    db.AddEvent(Date{9, 19, 11}, "vwev");
    db.AddEvent(Date{2019, 19, 11}, "aafv");
    db.AddEvent(Date{19, 1, 2}, "aafv");
    db.Print();

    // std::cout << db.DelDate({2009, 19, 11}) << std::endl;
    // db.FindDate({2009, 19, 11});
    // std::cout << db.DelEvent({2009, 19, 11}, "c") << "\n";

    return 0;
}