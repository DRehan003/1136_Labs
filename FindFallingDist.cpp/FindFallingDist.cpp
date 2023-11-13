#include <iostream>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double getSeconds ()  {
    double fallTime;
    cout << "Please enter the fall time (in seconds): ";
    cin >> fallTime;
    while (fallTime < 0)  {
        cout << "Error the fall time must be 0 or more." << endl;
        cout <<  "Please enter the fall time (in seconds): ";
        cin >> fallTime;
    }
    return fallTime;
}

double  findEarthFallDist (double fallTime) {
    double EarthFallDist = .5 * 9.81 * pow(fallTime, 2);
    return EarthFallDist;
}

double  findMoonFallDist (double fallTime) {
    double MoonFallDist = .5 * 1.625 * pow(fallTime, 2);
    return MoonFallDist;
}

void displayValues (double EarthFallDist, double MoonFallDist, double fallTime)  {
    cout << endl;
    cout << "The object traveled " << setprecision(3) << fixed << EarthFallDist << " meters in " << setprecision(1) << fixed << fallTime << " seconds on Earth." << endl;
    cout << "The object traveled " << setprecision(3) <<  fixed << MoonFallDist << " meters in " << setprecision(1) << fixed << fallTime << " seconds on the Moon." << endl;
}

int main() {
    double fallTime = getSeconds();
    double EarthFallDist = findEarthFallDist(fallTime);
    double MoonFallDist = findMoonFallDist(fallTime);
    displayValues( EarthFallDist, MoonFallDist, fallTime);
    return 0;
}
