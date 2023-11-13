#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool validKey(string fileNameKey)   {
    ifstream kFile;
    kFile.open(fileNameKey);
    if (!kFile)     {
        cout << "\"" << fileNameKey << "\"" << " could not be opened." << endl;
        return false;
    } else if(kFile.peek() == EOF)    {
        cout << "The file containing the key was empty." << endl;
        return false;
    } else    {
        kFile.close();
        return true;
    }
}

bool validResponse(string fileNameKey, string fileNameResponses, int &nAnswers, int &nResponses, char kAnswer, char rAnswer)    {
    ifstream kFile, rFile;
    kFile.open(fileNameKey);
    rFile.open(fileNameResponses);
    if (!rFile) {
        cout << "\"" << fileNameResponses << "\"" << " could not be opened." << endl;
        return false;
    }else   {
        while (kFile >> kAnswer)    {
                nAnswers++;
        }
        while (rFile >> rAnswer)    {
                nResponses++;
        }
        if (nResponses<nAnswers)    {
                cout << "File error! There is a mismatch between the number of questions and answers." << endl;
                return false;
        }else    {
            kFile.close();
            rFile.close();
            return true;
        }
    }
}

void displayResults( char kTotal[], char rTotal[], int nAnswers)    {
     int incorrect = 0;
     for (int i=0;i<nAnswers;i++)   {
        if (rTotal[i] != kTotal[i])     {
            incorrect++;
            cout << "Question " << (i+1) << " has incorrect answer '" << rTotal[i] << "', the correct answer is '" << kTotal[i] << "'." << endl;
        }
    }
    double grade = (nAnswers-incorrect);
    grade = (grade/nAnswers)*100;
    cout << incorrect << " questions were missed out of " << nAnswers << "." << endl;
    cout << "The student grade is " << fixed << setprecision(2) << grade << "%" << endl;
    if (grade>=72.5)    {
        cout << "The student has passed the quiz." << endl;
    }else   {
        cout << "The student has failed the quiz." << endl;
    }
}

int main()  {
    ifstream keyFile;
    ifstream responseFile;
    string key;
    string responses;
    int numAnswers=0;
    int numResponses=0;
    char keyAnswer;
    char response;
    char totalAnswers[50], totalResponses[50];
    cout << "Enter the name of the file containing the key." << endl;
    cin >> key;
    bool kValid = validKey(key);
    if (kValid == false)    {
        return 0;
    }
    cout << "Enter the name of the file containing the student's responses." << endl;
    cin >> responses;
    bool rVALID = validResponse(key, responses, numAnswers, numResponses, keyAnswer, response);
    if (rVALID == false)    {
        return 0;
    }
    keyFile.open(key);
    responseFile.open(responses);
    int x=0, y=0;
    while (keyFile >> keyAnswer)    {
        totalAnswers[x] = keyAnswer;
        x++;
    }
    while (responseFile >> response)    {
        totalResponses[y] = response;
        y++;
    }
    displayResults(totalAnswers, totalResponses, numAnswers);
    return 0;
}
