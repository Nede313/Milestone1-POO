#include <iostream>

#include "Activity.h"
#include "Calendar.h"
using namespace std;




int main() {
    Calendar calendar = Calendar();
    calendar.addActivity(Activity("nume", "desc", 22, 24+3));
    calendar.addActivity(Activity("nume", "desc", 20, 22));
    calendar.addActivity(Activity("nume", "desc", 8+24, 22+24));
    calendar.addActivity(Activity("nume", "desc", 22+24, 4+48));
    calendar.addActivity(Activity("nume", "desc", 2+24*5, 3+24*5));

    calendar.checkSleep();

    return 0;
}
