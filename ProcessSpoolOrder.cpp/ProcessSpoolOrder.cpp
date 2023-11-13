#include <iostream>
#include <iomanip>

using namespace std;

void getOrder(int&, int&, char&, double&);
int spoolsToShip(int, int);
int backOrder(int, int);
double calcShipping(double, int);
double spoolCharges(int);
double totalCharges(double, double);
void display(int, int, double, double, double);

    int main()  {
    int spoolsOrdered, spoolsInStock;
    double shippingAndHandling;
    char userChoice;
    getOrder(spoolsOrdered, spoolsInStock, userChoice, shippingAndHandling);
    cout << endl;
    int ready = spoolsToShip(spoolsOrdered, spoolsInStock);
    int backorder = backOrder(spoolsOrdered, spoolsInStock);
    double totalShipping = calcShipping(shippingAndHandling, ready);
    double spoolcharges = spoolCharges(ready);
    double total = totalCharges(spoolcharges, totalShipping);
    display(ready, backorder, spoolcharges, totalShipping, total);
    return 0;
}

    void getOrder(int& ordered, int& inStock, char&choice, double& charge) {
    cout << "Please enter the number of spools ordered: ";
    cin >> ordered;
    while (ordered < 1) {
        cout << "Error, the number of spools must be at least 1." << endl;
        cout << "Please enter the number of spools ordered: ";
        cin >> ordered;
    }
    
    cout << "Please enter the number of spools in stock: ";
    cin >> inStock;
    while (inStock < 0) {
        cout << "Error, the spools in stock should be 0 or more." << endl;
        cout << "Please enter the number of spools in stock: ";
        cin >> inStock;
    }
    
    cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
    cin >> choice;
    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        cout << "Please only enter 'Y' or 'N'" << endl;
        cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
        cin >> choice;
    }
    
    if (choice == 'y'|| choice == 'Y') {
        cout << "What is the shipping and handling charge? ";
        cin >> charge;
        while (charge < 0) {
            cout << "Error, the charge must be at least $0.00." << endl;
            cout << "What is the shipping and handling charge? ";
            cin >> charge;
        }
    }
    else if (choice == 'n'|| choice == 'N') {
        charge = 20.95;
    }
}

int spoolsToShip(int selected, int enough) {
    int prepared;
    if (selected <= enough) {
        prepared = selected;
    }
    else {
        prepared = enough;
    }
    return prepared;
}


int backOrder(int selected, int enough) {
    return (selected - enough);
}

double spoolCharges(int prepared) {
    return (prepared * 157.55);
}

double calcShipping(double charge, int prepared)   {
    return charge * prepared;
}


double totalCharges(double spoolCharges, double totalShipping) {
    return (spoolCharges + totalShipping);
}


void display(int ready, int backOrder, double spoolCharges, double totalShipping, double totalCharges) {
    cout << "Spools ready for shipping: " << ready << endl;
    if (backOrder > 0) {
        cout << "Spools on back order: " << backOrder << endl;
    }
    cout << "Charges for " << ready << " spools: $" << fixed << setprecision(2) << spoolCharges << endl;
    cout << "Shipping and handling for " << ready << " spools: $" << fixed << setprecision(2) << totalShipping << endl;
    cout << "Total charges (Incl. shipping & handling): $" << fixed << setprecision(2) << totalCharges << endl;
}
