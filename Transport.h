
#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <string>
using namespace std;

class Transport {
public:
    enum Transport_Type
    {
        BUS,
        METRO,
        CAR
     };
    Transport(Transport_Type type, int start_hour, int end_hour, string start_station, string end_station);
    Transport_Type getType();

    int getStartHour() const;
    int getEndHour() const;

    void setName(Transport_Type type);

private:
    Transport_Type type;
    int start_hour;
    int end_hour;
    string start_station;
    string end_station;
};


#endif //TRANSPORT_H
