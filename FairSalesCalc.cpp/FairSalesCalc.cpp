#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    double chiliDogs, cornDogs, chips, softDrinks, water;
    chiliDogs = 8;
    cornDogs = 6;
    chips = 2;
    softDrinks = 5;
    water = 4;
    
    double chiliDogsNum, cornDogsNum, chipsNum, softDrinksNum, waterNum;
    double chiliDogsCost, cornDogsCost, chipsCost, softDrinksCost, waterCost;
    double chiliDogsTax, cornDogsTax, chipsTax, softDrinksTax;
    double taxableItemsCost, taxAmount, nontaxableItemsCost, totalCost;
    
    cout << setprecision(2) << fixed;
    
    cout << "Enter the number of chili dogs: ";
    cin >> chiliDogsNum;
    cout << "Enter the number of corn Dogs: ";
    cin >> cornDogsNum;
    cout << "Enter the number of chips: ";
    cin >> chipsNum;
    cout << "Enter the number of soft drinks: ";
    cin >> softDrinksNum;
    cout << "Enter the number of water bottles: ";
    cin >> waterNum;
    
    chiliDogsCost = chiliDogsNum * chiliDogs;
    cornDogsCost = cornDogsNum * cornDogs;
    chipsCost = chipsNum * chips;
    softDrinksCost = softDrinksNum * softDrinks;
    waterCost = waterNum * water;
    
    chiliDogsTax = (chiliDogsCost/100) * 8.25;
    cornDogsTax = (cornDogsCost/100) * 8.25;
    chipsTax = (chipsCost/100) * 8.25;
    softDrinksTax = (softDrinksCost/100) * 8.25;
    
    taxableItemsCost = chiliDogsCost + cornDogsCost + chipsCost + softDrinksCost;
    taxAmount = chiliDogsTax + cornDogsTax + chipsTax + softDrinksTax;
    nontaxableItemsCost = waterCost;
    totalCost = taxableItemsCost + taxAmount + nontaxableItemsCost;
    
    cout << left << setw(13) << "Taxable:" << "$" << right << setw(8) << taxableItemsCost << "\n";
    cout << left << setw(13) << "Tax amount:" << "$" << right << setw(8) << taxAmount << "\n";
    cout << left << setw(13) << "Non-taxable:" << "$" << right << setw(8) << nontaxableItemsCost << "\n";
    cout << left << setw(13) << "Total:" << "$" << right << setw(8) << totalCost << "\n";
    
    return 0;
}
