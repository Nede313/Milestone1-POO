
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
    Transport(Transport_Type type, int start_hour, int end_hour, const string& start_station, string end_station);

    Transport_Type getType() const;
    void setType(Transport_Type type);

    int getStartHour() const;
    void setStartHour(int start_hour);

    int getEndHour() const;
    void setEndHour(int end_hour);

    string getStartStation() const;
    void setStartStation(const string& start_station);

    string getEndStation() const;
    void setEndStation(string end_station);

    long getId () const;


    Transport(const Transport &transport_cp);
    Transport& operator=(const Transport &transport_eq);

private:
    Transport_Type type;
    int start_hour;
    int end_hour;
    string start_station;
    string end_station;
    long id;

    ~Transport();

};


#endif //TRANSPORT_H
