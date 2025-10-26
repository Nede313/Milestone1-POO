
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

    bool addActivity(Activity activity);
    bool addTransport(Transport transport);
    void checkSleep();

    vector<Activity> getActivity();
    vector<Transport> getTransports();


};

#endif //CALENDAR_H
