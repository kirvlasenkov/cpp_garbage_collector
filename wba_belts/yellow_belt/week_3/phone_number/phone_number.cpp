#include "phone_number.h"
#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream str(international_number);

    char sign = str.get();
    getline(str, country_code_, '-');
    getline(str, city_code_, '-');
    getline(str, local_number_);

    if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
        throw invalid_argument("Phone");
    }


}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}
