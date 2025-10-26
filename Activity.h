
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string.h>
#include <string>
using namespace std;

class Activity {
private:
    string Name;
    string Description;
    int start_hour;
    int end_hour;

public:
    // Constructor
    Activity(string Name, string Description, int start_hour, int end_hour);

    // Copy Constructor
    Activity(const Activity &activity_cp);

    // = operator
    Activity& operator=(const Activity &activity_eq);

    string getName();
    void setName(string Name);

    string getDescription();
    int getStartHour() const;
    int getEndHour() const;

    ~Activity();

    friend ostream& operator<<(ostream& out, const Activity& m);
};

#endif //ACTIVITY_H
