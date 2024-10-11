//please test it to deal with any situation, also i didnot set an error of wrong input
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int timeToMinutes(const string& time) {
    int hour = stoi(time.substr(0, time.find(":")));
    int minute = stoi(time.substr(time.find(":") + 1));
    return hour * 60 + minute;
}
string minutesToTime(int minutes) {
    int hour = minutes / 60;
    int minute = minutes % 60;
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute;
    return ss.str();
}

vector<pair<int, int>> computeIntersection(const vector<pair<int, int>>& times1, const vector<pair<int, int>>& times2) {
    vector<pair<int, int>> result;
    for (const auto& t1 : times1) {
        for (const auto& t2 : times2) {
            if (t1.second > t2.first && t1.first < t2.second) { // Check for overlap
                result.push_back({max(t1.first, t2.first), min(t1.second, t2.second)});
            }
        }
    }
    return result;
}
vector<pair<int, int>> computeUnion(const vector<pair<int, int>>& times) {
    if (times.empty()) return {};
    vector<pair<int, int>> result;
    vector<pair<int, int>> sorted_times = times;
    sort(sorted_times.begin(), sorted_times.end());

    pair<int, int> current = sorted_times[0];
    for (const auto& time : sorted_times){
        if (time.first <= current.second) {
            current.second = max(current.second, time.second);
        } else {
            result.push_back(current); 
            current = time;
        }
    }
    result.push_back(current);
    return result;
}

// Subtract one set of time intervals from another
vector<pair<int, int>> subtractTimes(const vector<pair<int, int>>& times, const vector<pair<int, int>>& subtract) {
    vector<pair<int, int>> result;
    for (const auto& time : times) {
        int start = time.first;
        for (const auto& sub : subtract) {
            if (sub.first >= start && sub.first < time.second) {
                if (start < sub.first) {
                    result.push_back({start, sub.first});
                }
                start = sub.second;
            }
        }
        if (start < time.second) {
            result.push_back({start, time.second});
        }
    }
    return result;
} 
vector<pair<string, string>> parseTimes(string line) {
    vector<pair<string, string>> schedule;
    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    line.erase(remove(line.begin(), line.end(), '\''), line.end());
    stringstream ss(line);
    string time;
    vector<string> times;
    while (getline(ss, time, ',')) {
        times.push_back(time);
    }
    for (size_t i = 0; i < times.size(); i += 2) {
        if (i + 1 < times.size()) {
            schedule.push_back({times[i], times[i + 1]});
        }
    }
    return schedule;
}
int main() {
    cout << "person1_Schedule = ";
    string busyLine1;
    getline(cin, busyLine1);
    cout << "person1_DailyAct = ";
    string freeLine1;
    getline(cin, freeLine1);

    cout << "person2_Schedule = ";
    string busyLine2;
    getline(cin, busyLine2);
    cout << "person2_DailyAct = ";
    string freeLine2;
    getline(cin, freeLine2);

    auto busy1 = parseTimes(busyLine1);
    auto free1 = parseTimes(freeLine1);
    auto busy2 = parseTimes(busyLine2);
    auto free2 = parseTimes(freeLine2);

    vector<pair<int, int>> busyPeriods, freePeriods, availablePeriods;
    for (const auto& p : busy1) busyPeriods.push_back({timeToMinutes(p.first), timeToMinutes(p.second)});
    for (const auto& p : busy2) busyPeriods.push_back({timeToMinutes(p.first), timeToMinutes(p.second)});
    busyPeriods = computeUnion(busyPeriods);

    for (const auto& p : free1) freePeriods.push_back({timeToMinutes(p.first), timeToMinutes(p.second)});
    vector<pair<int, int>> freePeriods2;
    for (const auto& p : free2) freePeriods2.push_back({timeToMinutes(p.first), timeToMinutes(p.second)});
    freePeriods = computeIntersection(freePeriods, freePeriods2);

    availablePeriods = subtractTimes(freePeriods, busyPeriods);

    cout << "duration_of_meeting = ";
    int duration;
    cin >> duration;

    vector<string> outputPeriods;
    for (const auto& p : availablePeriods) {
        if (p.second - p.first >= duration) {
            outputPeriods.push_back("['" + minutesToTime(p.first) + "','" + minutesToTime(p.second) + "']");
        }
    }

    if (outputPeriods.size() == 1) {
        cout << outputPeriods[0];
    } else if (outputPeriods.size() > 1) {
        cout << "[";
        for (size_t i = 0; i < outputPeriods.size(); ++i) {
            cout << outputPeriods[i];
            if (i < outputPeriods.size() - 1) cout << ",";
        }
        cout << "]";
    }

    return 0;
}

