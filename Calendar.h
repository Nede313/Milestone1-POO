
#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>

#include "Activity.h"
#include "Transport.h"
using namespace std;

class Calendar {
private:
    vector<Activity> activities;
    vector<Transport> transports;
public:
    Calendar();

    bool addActivity(const Activity& activity);
    bool addTransport(const Transport &transport);
    void checkSleep();

    bool removeActivity(int id);
    bool removeTransport(int id);

    Activity getActivity(int id);
    Transport getTransport(int id);

    Calendar(const Calendar &calendar_cp);
    Calendar& operator=(const Calendar &calendar_eq);

    ~Calendar();
};

#endif //CALENDAR_H
