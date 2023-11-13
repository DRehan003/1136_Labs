#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    double value;
    int totalR=0;
    int validR=0;
    int invalidR=0;
    double totalValue= 0.0;
    cout << "Enter the input file name: " << endl;
    getline(cin, fileName);
    inputFile.open(fileName);
    if(inputFile)   {
        outputFile.open("badvalues.txt");
        if(outputFile)  {
            while(inputFile >> value)  {
                totalR++;
                if(value >= 1 && value <= 150)    {
                    totalValue = totalValue + value;
                    validR++;
                }   else    {
                    invalidR++;
                    outputFile << fixed;
                    outputFile << setprecision(3) << value << endl;
                }
            }
            cout << fixed << setprecision(2);
            cout <<"Total number of values read: " << totalR << endl;
            cout <<"Valid values read: " << validR << endl;
            cout <<"Invalid values read: " << invalidR << endl;
            if(validR == 0)   {
                cout <<"The file did not contain any valid values." << endl;
            }   else    {
                cout <<"The average of the valid numbers read = "<<(totalValue/validR)<< endl;
            }
            outputFile.close();
            inputFile.close();
        }   else    {
            cout <<"Error output file could not be opened." << endl;
            inputFile.close();
            return 0;
        }
    }   else    {
        cout <<"The file \"nofile.txt\" could not be opened." << endl;
    }
    return 0;
}
