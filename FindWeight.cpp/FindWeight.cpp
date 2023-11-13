#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    double mass,earthWeight,venusWeight,MarsWeight;
    
    cout << "Mass of an object in kilograms: ";
    cin >> mass;
    earthWeight = (mass * 9.807);
    venusWeight = (mass * 8.87);
    MarsWeight = (mass * 3.7);
    
    cout << setprecision(4) << fixed;
    
    if ( mass <= 0) {
        cout << "mass must be greater than zero" << endl;
    } else {
        cout << left << setw(6) << "Planet" << "\t" << right << setw(14) << "Weight (N)" << endl;
        cout << endl;
        cout << left << setw(6) << "Earth" << "\t" << right << setw(14) << earthWeight;
        if (earthWeight > 1500) {
            cout << "\t" << "The object is heavy\n";
        } else if (earthWeight < 5) {
            cout << "\t" << "The object is light\n";
        } else {
            cout << endl;
        }
        cout << left << setw(6) << "Venus" << "\t" << right << setw(14) << venusWeight << "\n";
        cout << left << setw(6) << "Mars" << "\t" << right << setw(14) << MarsWeight << endl;
    }
    return 0;
}
