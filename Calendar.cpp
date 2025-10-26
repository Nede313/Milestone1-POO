//
// Created by Nedee on 10/26/2025.
//

#include "Calendar.h"
#include <algorithm>
#include <iostream>

Calendar::Calendar() {
}

bool Calendar::addActivity(Activity activity) {
    if (activity.getStartHour() >= activity.getEndHour() ||
        activity.getEndHour() > 7 * 24) {
        return false;
        }

    for (int i = 0; i < this->activities.size(); ++i) {
        // Check if it is intercalating
        if (this->activities[i].getStartHour() < activity.getEndHour()
            && activity.getStartHour() < this->activities[i].getEndHour()) {
            return false;
        }
    }
    for (int i = 0; i < this->transports.size(); ++i) {
        // Check if it is intercalating
        if (this->transports[i].getStartHour() < activity.getEndHour()
            && activity.getStartHour() < this->transports[i].getEndHour()) {
            return false;
            }
    }
    this->activities.push_back(activity);
    sort(this->activities.begin(), this->activities.end(), [](const Activity &a, const Activity &b) {
        return a.getStartHour() < b.getStartHour();
    });
    return true;
}

bool Calendar::addTransport(Transport transport) {
    if (transport.getStartHour() >= transport.getEndHour() ||
        transport.getEndHour() > 7 * 24) {
        return false;
    }

    for (int i = 0; i < this->transports.size(); ++i) {
        // Check if it is intercalating
        if (this->transports[i].getStartHour() < transport.getEndHour()
            && transport.getStartHour() < this->transports[i].getEndHour()) {
            return false;
            }
    }
    for (int i = 0; i < this->activities.size(); ++i) {
        // Check if it is intercalating
        if (this->activities[i].getStartHour() < transport.getEndHour()
            && transport.getStartHour() < this->activities[i].getEndHour()) {
            return false;
            }
    }
    this->transports.push_back(transport);
    sort(this->transports.begin(), this->transports.end(), [](const Transport &a, const Transport &b) {
        return a.getStartHour() < b.getStartHour();
    });
    return true;
}

void Calendar::checkSleep() {
    vector<pair<int,int>> intervals;
    for (int i = 0; i < this->activities.size(); ++i) {
        intervals.push_back(make_pair(this->activities[i].getStartHour(),this->activities[i].getEndHour()));
    }
    for (int i = 0; i < this->transports.size(); ++i) {
        intervals.push_back(make_pair(this->transports[i].getStartHour(),this->transports[i].getEndHour()));
    }
    sort(intervals.begin(), intervals.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.first < b.first;
    });

    vector<pair<int,int>> intervalsToCheck;
    intervalsToCheck.push_back(make_pair(22,22+12));
    intervalsToCheck.push_back(make_pair(22+24,22+24+12));
    intervalsToCheck.push_back(make_pair(22+48,22+48+12));
    intervalsToCheck.push_back(make_pair(22+72,22+72+12));
    intervalsToCheck.push_back(make_pair(22+96,22+96+12));
    intervalsToCheck.push_back(make_pair(22+120,22+120+12));

    vector<bool> sleepHoursCheck = {true, true, true, true, true, true, true};

    for (int i = 0; i < intervalsToCheck.size(); ++i) {
        for (int j = 0; j < intervals.size(); ++j) {
            if (intervalsToCheck[i].first < intervals[j].second && intervals[j].second < intervalsToCheck[i].second) {
                if (j < intervals.size() - 1 && intervalsToCheck[i].first < intervals[j+1].first && intervals[j+1].first < intervalsToCheck[i].second) {
                    if (intervals[j+1].first - intervals[j].second < 9) {
                        sleepHoursCheck[i] = false;
                    } else {
                        sleepHoursCheck[i] = true;
                        break;
                    }
                } else {
                    if (intervals[j].second < intervalsToCheck[i].second && intervals[j].second > intervalsToCheck[i].second-9) {
                        sleepHoursCheck[i] = false;
                        break;
                    }
                }
            } else if (intervalsToCheck[i].first < intervals[j].first && intervals[j].first < intervalsToCheck[i].second) {
                if (intervals[j].first < intervalsToCheck[i].second-3) {
                    sleepHoursCheck[i] = false;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < intervalsToCheck.size(); ++i) {
        cout << sleepHoursCheck[i] << " ";
    }
}
