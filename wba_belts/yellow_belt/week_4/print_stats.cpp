#include <iostream>
#include <algorithm>
#include <vector>

/*
template<typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);


enum class Gender {
    FEMALE,
    MALE
};


struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};


void PrintStats(std::vector<Person> &persons) {
    // for full group
    std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << '\n';

    // for females
    auto it_females = std::partition(persons.begin(), persons.end(),
                                     [](Person &person) {
                                         return person.gender == Gender::FEMALE;
                                     });
    std::cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it_females) << '\n';

    // for males
    auto it_males = std::partition(persons.begin(), persons.end(),
                                   [](Person &person) {
                                       return person.gender == Gender::MALE;
                                   });
    std::cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it_males) << '\n';

    // for employed females
    auto it_employed_females = std::partition(persons.begin(), persons.end(),
                                     [](Person& person) {
                                         return person.gender == Gender::FEMALE &&
                                         person.is_employed;
                                     });
    std::cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it_employed_females) << '\n';

    // for unemployed females
    auto it_unemployed_females = std::partition(persons.begin(), persons.end(),
                                              [](Person& person) {
                                                  return person.gender == Gender::FEMALE &&
                                                  !person.is_employed;
                                              });
    std::cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), it_unemployed_females) << '\n';

    // for employed males
    auto it_employed_males = std::partition(persons.begin(), persons.end(),
                                              [](Person& person) {
                                                  return person.gender == Gender::MALE &&
                                                  person.is_employed;
                                              });
    std::cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it_employed_males) << '\n';

    // for unemployed males
    auto it_unemployed_males = std::partition(persons.begin(), persons.end(),
                                                [](Person& person) {
                                                    return person.gender == Gender::MALE &&
                                                    !person.is_employed;
                                                });
    std::cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), it_unemployed_males) << '\n';


}
*/