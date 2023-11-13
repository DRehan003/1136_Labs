#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    long long int second;
    long long int day = 0;
    long long int hour = 0;
    long long int minute = 0;
    cout << "Enter a number of seconds";
    cin >> second;
    if (second < 0) {
        cout << "seconds must be greater than zero" << endl;
    } else {
        while (second >= 86400) {
            if (second >= 86400) {
                day++;
                second -= 86400;
            }
        }
        while (second >= 3600) {
            if (second >= 3600) {
                hour++;
                second -= 3600;
            }
        }
        while (second >= 60) {
            if (second >= 60) {
                minute++;
                second -= 60;
            }
        }
        if (day > 0) {
            cout << "Day(s): " << day << endl;
        }
        if (hour > 0) {
            cout << "Hour(s): " << hour << endl;
        }
        if (minute > 0) {
            cout << "Minute(s): " << minute << endl;
        }
        if (second > 0) {
            cout << "Remaining second(s): " << second;
        }
    }
    return 0;
}
