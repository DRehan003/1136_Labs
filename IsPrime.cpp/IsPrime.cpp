#include<iostream>
using namespace std;

int main()
{
    int firstEleven[11]={2,3,5,7,11,13,17,19,23,29,31};
    unsigned int number;
    bool flag = true;
    cout  <<  "Enter a positive whole number in the range 2 through 1000: ";
    cin  >>  number;
    if(number < 2 || number > 1000)
    {
        cout << number << " is not in th range 2 through 1000" << endl;
        return 0;
    }
    for(int i=0; i<11; i++)
    {
        if(number == firstEleven[i])
        {
            cout << number << " is prime." << endl;
            return 0;
        }
    }
    for(int i=0; i<11; i++)
    {
        if(number % firstEleven[i] == 0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << number << " is prime." << endl;
    else
    {
        cout << number << " is divisible by:" << endl;
        for(int i=0; i<11; i++)
        {
            if(number % firstEleven[i] == 0)
            {
                cout << firstEleven[i] << endl;
            }
        }
    }
    return 0;
}
