#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Activity.h"
#include "Calendar.h"
using namespace std;

int main() {
    srand(time(NULL));
    const Transport T1 = Transport(Transport::BUS, 12, 15, "Pacii", "Unirii");
    const Transport T2 = Transport(Transport::BUS, 11, 12, "Pacii", "Unirii");

    Calendar C1;
    bool ret = C1.addTransport(T1);
    cout << ret << endl;
    ret = C1.addTransport(T2);
    cout << ret << endl;

    ret = C1.removeTransport(T2.getId());
    cout << ret << endl;
    ret = C1.removeTransport(T2.getId());
    cout << ret << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    const Activity A1 = Activity("antrenament", "am antrenament cu alex", 18, 20);
    const Activity A2 = Activity("antrenament", "am antrenament cu cosmin", 15, 17);
    bool ret2 = C1.addActivity(A1);
    cout << ret2 << endl;
    ret2 = C1.addActivity(A2);
    cout << ret2 << endl;

    ret2 = C1.removeActivity(A2.getId());
    cout << ret2 << endl;
    ret2 = C1.removeActivity(A2.getId());
    cout << ret2 << endl;


    return 0;
}
