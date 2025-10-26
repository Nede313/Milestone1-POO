
#include "Transport.h"

#include <iostream>
using namespace std;

Transport::Transport(Transport_Type type, int start_hour, int end_hour, string start_station, string end_station) {
    this->type = type;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->start_station = start_station;
    this->end_station = end_station;
}

Transport::Transport_Type Transport::getType() {
    return this->type;
}

void Transport::setName(Transport_Type type) {
    this->type = type;
}

int Transport::getStartHour() const {
    return this->start_hour;
}
int Transport::getEndHour() const {
    return this->end_hour;
}
