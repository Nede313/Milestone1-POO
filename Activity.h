
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
    int id;

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
    void setDesc(string Description);

    int getStartHour() const;
    void setStartHr(int start_hour);

    int getEndHour() const;
    void setEndHr(int end_hour);

    long getId() const;

    ~Activity();

    friend ostream& operator<<(ostream& out, const Activity& m);
};

#endif //ACTIVITY_H
