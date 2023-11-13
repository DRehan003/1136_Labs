#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    int medium;
    double distance;
    double seconds;
    double air, water, steel;
    air = 1133.2;
    water = 4871.0;
    steel = 16400.0;
    
    cout << setprecision(4) << fixed;
    
    cout << "\tTime for Sound to Travel through a Medium given Distance\n\n";
    cout << "1 - Air\n" ;
    cout << "2 - Water\n" ;
    cout << "3 - Steel\n\n" ;
    cout << "Enter the number of the medium: \n";
    cin >> medium;
    
    if (medium > 0 && medium < 4) {
        cout << "Enter distance to travel (in feet): \n";
        cin >> distance;
    } else {
        cout << "the entry is invalid, ";
        cout << "run the program again ";
        exit (1);
    }
    if (distance > 0) {
        switch ( medium ) {
            case 1:
                seconds = distance / air;
                cout << "In air it will take " << seconds << " seconds to travel " << distance << " feet.\n";
                break;
            case 2:
                seconds = distance / water;
                cout << "In water it will take " << seconds << " seconds to travel " << distance << " feet.\n";
                break;
            case 3:
                seconds = distance / steel;
                cout << "In steel it will take " << seconds << " seconds to travel " << distance << " feet.\n";
                break;
        }
    } else {
        cout << "the distance must be greater than zero";
        exit (1);
    }
    return 0;
}
