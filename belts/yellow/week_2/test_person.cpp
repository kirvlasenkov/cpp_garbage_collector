#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>



template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
  if (t != u) {
    std::ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw std::runtime_error(os.str());
  }
}

void Assert(bool b, const std::string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name) {
    try {
      func();
      std::cerr << test_name << " OK" << std::endl;
    } catch (std::exception& e) {
      ++fail_count;
      std::cerr << test_name << " fail: " << e.what() << std::endl;
    } catch (...) {
      ++fail_count;
      std::cerr << "Unknown exception caught" << std::endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
    void ChangeFirstName(int year, const std::string first_name) {
        year_to_name[year].first = first_name;
    }

    void ChangeLastName(int year, const std::string last_name) {
        year_to_name[year].second = last_name;
    }

    std::string GetFullName(int year) {
        std::string first_name = "";
        std::string last_name = "";
        for (auto const &item : year_to_name) {
            if (item.first <= year && !(item.second.first.empty())) {
                first_name = item.second.first;
            }
            if (item.first <= year && !(item.second.second.empty())) {
                last_name = item.second.second;
            }

        }

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        else {
            return first_name + " " + last_name;
        }
    }

private:
    std::map<int, std::pair<std::string, std::string>> year_to_name;

};

void TestFirstName() {
    Person person;
    person.ChangeFirstName(1900, "Name_1900");
    person.ChangeFirstName(1993, "Name_1993");
    person.ChangeFirstName(1940, "Name_1940");

    AssertEqual(person.GetFullName(1940), "Name_1940 with unknown last name");
    AssertEqual(person.GetFullName(1921), "Name_1900 with unknown last name");
    AssertEqual(person.GetFullName(2000), "Name_1993 with unknown last name");
    AssertEqual(person.GetFullName(1800), "Incognito");
}

void TestLastName() {
    Person person;
    person.ChangeLastName(1900, "Name_1900");
    person.ChangeLastName(1993, "Name_1993");
    person.ChangeLastName(1940, "Name_1940");

    AssertEqual(person.GetFullName(1940), "Name_1940 with unknown first name");
    AssertEqual(person.GetFullName(1921), "Name_1900 with unknown first name");
    AssertEqual(person.GetFullName(2000), "Name_1993 with unknown first name");
    AssertEqual(person.GetFullName(1800), "Incognito");
}

void TestFullName() {
    Person person;
    person.ChangeFirstName(1900, "Name_1900");
    person.ChangeFirstName(1993, "Name_1993");
    person.ChangeFirstName(1940, "Name_1940");

    person.ChangeLastName(1900, "Name_1900");
    person.ChangeLastName(1993, "Name_1993");
    person.ChangeLastName(1940, "Name_1940");

    AssertEqual(person.GetFullName(1940), "Name_1940 Name_1940");
    AssertEqual(person.GetFullName(1921), "Name_1900 Name_1900");
    AssertEqual(person.GetFullName(2000), "Name_1993 Name_1993");
    AssertEqual(person.GetFullName(1800), "Incognito");

}

int main() {
  TestRunner runner;
  runner.RunTest(TestFirstName, "First name");
  runner.RunTest(TestLastName, "Last name");
  runner.RunTest(TestFullName, "full name");

  return 0;
}
