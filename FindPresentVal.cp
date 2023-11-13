#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int readYears ()  {
    int years;
    cout << "Enter the whole number of years of the investment: ";
    cin >> years;
    while (years <= 0)  {
        cout << "Error the number of years must be greater than zero." << endl;
        cout << "Enter the whole number of years of the investment: ";
        cin >> years;
    }
    return years;
}

double presentValue(double futureValue, double interestRate, int numberYears)   {
    double presentVal;
    presentVal = futureValue / pow( (1 + interestRate) , numberYears);
    return presentVal;
}

void displayResults (double presentValue, double futureValue, double interestRate, int years) {
    cout << setprecision(2) << fixed << "Present value: $" << presentValue << endl;
    cout << "Years: " << years << endl;
    cout << setprecision(3) << fixed << "Annual interest rate: " << interestRate*100 << "%" << endl;
    cout << setprecision(2) << fixed << "Future value: $" << futureValue << endl;
}

int main() {
    double presentVal, futureValue, interestRate;
    int years;
    cout << "Enter the future value of the investment: ";
    cin >> futureValue;
    while (futureValue < 0)  {
        cout << "Error the future value must be greater than zero." << endl;
        cout << "Enter the future value of the investment: ";
        cin >> futureValue;
    }
    cout << "Enter the annual interest rate: ";
    cin >> interestRate;
    while (interestRate < 0)  {
        cout << "Error the annual interest rate must be greater than zero." << endl;
        cout << "Enter the annual interest rate: ";
        cin >> interestRate;
    }
    interestRate = interestRate / 100;
    years = readYears();
    presentVal = presentValue(futureValue, interestRate, years);
    displayResults(presentVal, futureValue, interestRate, years);
    return 0;
}
