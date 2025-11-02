
#include "Transport.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Transport::Transport(Transport_Type type, int start_hour, int end_hour, const string& start_station, string end_station) {
    this->id = rand();
    this->type = type;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->start_station = start_station;
    this->end_station = end_station;
}

Transport::Transport(const Transport &transport_cp) {
    this->id = transport_cp.id;
    this->type = transport_cp.type;
    this->start_hour = transport_cp.start_hour;
    this->end_hour = transport_cp.end_hour;
    this->start_station = transport_cp.start_station;
    this->end_station = transport_cp.end_station;
}

Transport& Transport::operator=(const Transport &transport_eq) {
    if (this != &transport_eq) {
        this->id = transport_eq.id;
        this->type = transport_eq.type;
        this->start_hour = transport_eq.start_hour;
        this->end_hour = transport_eq.end_hour;
        this->start_station = transport_eq.start_station;
        this->end_station = transport_eq.end_station;
    }
    return *this;
}

void Transport::setType(Transport_Type type) {
    this->type = type;
}

int Transport::getStartHour() const {
    return this->start_hour;
}

void Transport::setStartHour(int start_hour) {
    this->start_hour = start_hour;
}

int Transport::getEndHour() const {
    return this->end_hour;
}

void Transport::setEndHour(int end_hour) {
    this->end_hour = end_hour;
}

string Transport::getStartStation() const {
    return this->start_station;
}

void Transport::setStartStation(const string& start_station) {
    this->start_station = start_station;
}

long Transport::getId() const {
    return this->id;
}

