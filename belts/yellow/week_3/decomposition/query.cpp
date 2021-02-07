#include "query.h"
#include <iostream>

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

