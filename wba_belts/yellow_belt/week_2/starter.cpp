#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <utility>


using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream &operator>>(istream &is, Query &q) {
    string operation;
    is >> operation;

    if (operation == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int num_of_route;
        is >> num_of_route;
        q.stops.resize(num_of_route);
        for (string &stop : q.stops) {
            cin >> stop;
        }

    } else if (operation == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;

    } else if (operation == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;

    } else if (operation == "ALl_BUSES") {
        q.type = QueryType::AllBuses;

    }

    return is;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
    if (r.buses.empty()) {
        os << "No stop" << endl;
    } else {
        for (const auto &bus : r.buses) {
            os << bus << " ";
        }
        os << endl;
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    map<string, vector<string>> stops_for_buses;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
    if (r.stops_for_buses.empty()) {
        os << "No bus" << endl;
    } else {
        for (const auto &stop_and_buses : r.stops_for_buses) {
            os << "Stop " << stop_and_buses.first << ":";
            if (stop_and_buses.second.size() == 1) {
                os << " no interchange" << endl;
            } else {
                for (const auto &bus : stop_and_buses.second) {
                    if (bus != r.bus) {
                        os << " " << bus;
                    }
                }
                os << endl;
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r) {
    if (r.buses_to_stops.empty()) {
        os << "No buses" << endl;
    } else {
        for (const auto &bus_and_stops : r.buses_to_stops) {
            os << "Bus " << bus_and_stops.first << ":";
            for (const auto &stop : bus_and_stops.second) {
                os << " " << stop;
            }
            os << endl;
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string &bus, const vector<string> &stops) {
        stops_to_buses.insert(make_pair(bus, stops));
        for (const auto &stop : stops) {
            buses_to_stops[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string &stop) const {
        if (stops_to_buses.count(stop) == 0) {
            return BusesForStopResponse{vector<string>()};
        } else {
            return BusesForStopResponse{stops_to_buses.at(stop)};
        }
    }

    StopsForBusResponse GetStopsForBus(const string &bus) const {
        map<string, vector<string>> result;

        if (buses_to_stops.count(bus) > 0) {
            for (const auto &stop : buses_to_stops.at(bus)) {
                result.insert(make_pair(stop, stops_to_buses.at(stop)));
            }
        }
        return StopsForBusResponse{bus, result};
    }

    AllBusesResponse GetAllBuses() const {
        return AllBusesResponse{buses_to_stops};
    }

private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};


// Не меняя тела функции main, реализуйте функции и классы выше

/*
int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
} */
