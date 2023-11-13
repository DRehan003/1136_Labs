#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    double dollars, mexicanPesos, euros, japaneseYen;
    
    cout << "Enter an amount to be converted in U.S dollar(s) form: ";
    cin >> dollars;
    
    mexicanPesos = (dollars * 20.06);
    euros = (dollars * 0.99);
    japaneseYen = (dollars * 143.08);
    
    cout << setprecision(2) << fixed;
    cout << right;
    
    cout << setw(10) << "Dollars" << "\t";
    cout << setw(10) << "Pesos" << "\t";
    cout << setw(10) << "Euros" << "\t";
    cout << setw(10) << "Yen" << endl;
    
    cout << setw(10) << dollars << "\t";
    cout << setw(10) << mexicanPesos << "\t";
    cout << setw(10) << euros << "\t";
    cout << setw(10) << japaneseYen << endl;
    return 0;
}
