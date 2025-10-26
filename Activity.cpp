
#include "Activity.h"

#include <iostream>
using namespace std;

Activity::Activity(string Name, string Description, int start_hour, int end_hour) {
    this->Name = Name;
    this->Description = Description;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
}

Activity::Activity(const Activity &activity_cp) {
    this->Name = activity_cp.Name;
    this->Description = activity_cp.Description;
    this->start_hour = activity_cp.start_hour;
    this->end_hour = activity_cp.end_hour;
}

Activity& Activity::operator=(const Activity &activity_eq) {
    if (this != &activity_eq) {
        this->Name = activity_eq.Name;
        this->Description = activity_eq.Description;
        this->start_hour = activity_eq.start_hour;
        this->end_hour = activity_eq.end_hour;
    }
    return *this;
}

Activity::~Activity() {}

ostream& operator<<(ostream& out, const Activity& m) {
    out << "Name: " << m.Name
        << ", Description: " << m.Description
        << ", Start Hour: " << m.start_hour
        << ", End Hour: " << m.end_hour;
    return out;
}

string Activity::getName() {
    return this->Name;
}

void Activity::setName(string Name) {
    this->Name = Name;
}

string Activity::getDescription() {
    return this->Description;
}
int Activity::getStartHour() const {
    return this->start_hour;
}
int Activity::getEndHour() const {
    return this->end_hour;
}
