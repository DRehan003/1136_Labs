#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
int main()
{
    string nameOfFile;
    cout << "Enter input file name: " << endl;
    cin >> nameOfFile;
    ifstream inputFile;
    inputFile.open(nameOfFile);
    if (!inputFile) {
        cout << "Error File " << "\"" << nameOfFile << "\"" << " could not be opened." << endl;
    }
    ofstream outputFile;
    outputFile.open("saleschart.txt");
    unsigned int number_Of_Stores;
    long long storeSale;
    if (inputFile.peek() != std::ifstream::traits_type::eof())
    {
        outputFile << "SALES BAR CHART" << endl;
        outputFile << "(Each * equals 5,000 dollars)" << endl;
    }

    while (inputFile >> number_Of_Stores >> storeSale)
    {
        int number = (storeSale / 5000);

        if (number_Of_Stores >= 100 || number_Of_Stores <= 0)
        {
            cout << "Error! The store number " << number_Of_Stores << " is not valid.";
            cout << endl;
        }   else    {
            if (storeSale < 0)  {
                cout << "Error! The sales value for store " << number_Of_Stores << " is negative." << endl;
            }   else    {
                outputFile << "Store " << setw(2) << number_Of_Stores << ": ";
                for (int d = 0; d < number; d++)    {
                    outputFile << "*";
                }
                outputFile << endl;
            }
        }
    }
}
