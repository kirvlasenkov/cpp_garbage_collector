#include <iostream>
#include <exception>
#include <string>


using namespace std;

string AskTimeServer() {
    try {
        return "00:00:01";
    } catch (const system_error& run) {}

}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;

        } catch(const system_error& sys) {
            return last_fetched_time;
        }

    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
