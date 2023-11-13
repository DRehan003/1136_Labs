/*
 Matching Strings
 
 #include <iostream>
 #include <string>
 #include <math.h>
 using namespace std;
 
 int main() {
 
 string str1;
 string str2;
 int same = 0;
 
 cin >> str1;
 cin >> str2;
 
 for (int i = 0; i < fmin(str1.length(), str2.length()); i++) {
 if (str1.at(i) == str2.at(i) ) {
 same++;
 }
 }
 
 if (same == 1) {
 cout << same << " character matches";
 } else {
 cout << same << " characters match";
 }
 return 0;
 }
 */
 
/*     Find Largest Number
#include <iostream>
using namespace std;

int main() {

    int num = 0;
    int max = 0;
    while (num >= 0) {
        cin >> num;
        if (max < num) {
            max = num;
        }
    }
    cout << max << endl;
   return 0;
}
*/

/* palindrome
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {

   string str, palindrome, reverse;
   getline (cin, str);
   for (int i = 0; i < str.length(); i++) {
      if (str.at(i) != ' ') {
         palindrome += str.at(i);
      }
   }

   for (int i = str.length() - 1; i < str. length(); i--) {
      if (str.at(i) != ' ') {
         reverse = reverse + str.at(i);
      }
   }
   
   if (palindrome == reverse) {
      cout << "palindrome: " << str << endl;
   } else {
      cout << "not a palindrome: " << str << endl;
   }
   return 0;
}
*/

/*  Output values below an amount
#include <iostream>
#include <vector>
using namespace std;

int main() {

   int arraySize;
   cin >> arraySize;
   vector<int> myVector;
   
   for (int i = 0; i < arraySize; i++) {
      int x;
      cin >> x;
      myVector.push_back(x);
   }
   
   int x;
   cin >> x;
   
    for ( int myInt : myVector ) {
        if (myInt <= x ) {
            cout << myInt << ",";
        }
    }
   cout << endl;
   return 0;
}


#include <iostream>

int x;
void reverseArrayCopy(int original[], int originalSize, int newVersion[], int newVersionSize) {
   if (newVersionSize < originalSize) {
      x=1;
      return;
   }
   else {
      x=0;
      for ( int i=0; i < newVersionSize; i++) {
         int myInt = newVersionSize - i - 1;
         newVersion[myInt] = original[i];
      }
   }
}
int main() {
    const int ARRAY_SIZE = 5;
    int originalSize, newVersionSize;
    int original[ARRAY_SIZE];
    int newArray[ARRAY_SIZE];
    
    for ( int i=0; i<ARRAY_SIZE; i++) {
        std::cin >> original[i];
    }
    originalSize = sizeof(original) / sizeof(original[0]);
    newVersionSize = sizeof(newArray) / sizeof(newArray[0]);
    
    reverseArrayCopy(original, originalSize, newArray, newVersionSize);
    if (x == 0) {
        for ( int i=0; i < newVersionSize; i++) {
            std::cout << newArray[i] << " ";
        }
    } else {
            for ( int i=0; i < originalSize; i++) {
                std::cout << original[i] << " ";
            }
        }
    std::cout << std::endl;
    return 0;
}
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>


using namespace std;
class Student   {
    public:
        string lname;
        string fname;
        int marks[3];
        char grade;
        void calculate_grade()  {
            double sum = 0;
            for(int i=0;i<3;i++)    {
                sum+= marks[i];
            }
            double average = sum/3;
            if(average>=90 && average<100)
                this->grade = 'A';
            else if(average>=80)
                this->grade = 'B';
            else if(average>=70)
                this->grade = 'C';
            else if(average>=60)
                this->grade= 'D';
            else this->grade = 'F';
        }
};
vector<Student> read_file(string fileName){
    fstream fin;
    fin.open(fileName);
    vector<Student> list;
    vector<string> row ;
    string line, word, temp;
    while(getline(fin,line)){
        row.clear();
        stringstream s(line);
        while(getline(s,word,'\t'))     {
            row.push_back(word);
        }
        Student st;
        st.fname = row[0];
        st.lname = row[1];
        st.marks[0] = stoi(row[2]);
        st.marks[1] = stoi(row[3]);
        st.marks[2] = stoi(row[4]);
        st.calculate_grade();
        list.push_back(st);
    }
    fin.close();
    return list;
}
void writeFile(string filename, vector<Student> list)   {
    ofstream fin(filename);
    for(int i=0;i<list.size();i++){
        string line = list[i].fname+"\t"+list[i].lname+"\t"+to_string(list[i].marks[0])+"\t"
        +to_string(list[i].marks[1])+"\t"+to_string(list[i].marks[2])+"\t"+list[i].grade+"\n";
        fin<<line;
    }
    double average1 =0,average2 =0 ,average3 = 0;
    for(int i=0;i<list.size();i++){
        average1+=list[i].marks[0];
        average2+=list[i].marks[1];
        average3+=list[i].marks[2];
    }
    average1/=list.size();
    average2/=list.size();
    average3/=list.size();
    fin<<"\n"<<"Averages: "<<"midterm1 "<<fixed<<setprecision(2)<<average1<<", midterm2 "<<setprecision(2)<<average2<<", final "<<setprecision(2)<<average3<<"\n";
         fin.close();
}
int main()  {
    cout<<"Enter the filename: ";
    string filename;
    cin>>filename;
    vector<Student> list;
    list = read_file(filename);
    writeFile("report.txt",list);
}

/*
 #include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double calcShipping(double spoolsNum, double shippingHandling)   {
    double costOfSpools = 157.55;
    double totalCost;
    
    cout << "Spools ready for shipping: " << spoolsNum << endl;
    cout << "Charges for " << spoolsNum << " spools: $" << setprecision(2) << fixed << spoolsNum * costOfSpools<< endl;
    cout << "Shipping and handling for " << setprecision(0) << fixed << spoolsNum << " spools: $"  << setprecision(2) << fixed << shippingHandling << endl;
    cout << "Total charges (Incl. shipping & handling): $" << setprecision(2) << fixed << ((spoolsNum * costOfSpools) + shippingHandling) << endl;
    return ((spoolsNum * costOfSpools) + shippingHandling);
}

void getOrder ()    {
    int spoolsNum;
    double extraCharge;
    int spoolsInStock;
    char shippingHandling;
    
    cout << "Please enter the number of spools ordered: ";
    cin >> spoolsNum;
    while (spoolsNum < 1)   {
        cout << "Error, the number of spools must be at least 1. ";
        cout << "Please enter the number of spools ordered: ";
        cin >> spoolsNum;
    }
    
    cout << "Please enter the number of spools in stock: ";
    cin >> spoolsInStock;
    while (spoolsInStock < 0)   {
        cout << "Error, the spools in stock should be 0 or more. ";
        cout << "Please enter the number of spools in stock: ";
        cin >> spoolsInStock;
    }
    
    cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
    cin >> shippingHandling;
    if (shippingHandling == 'y')  {
        cout << "What is the shipping and handling charge? ";
        cin >> extraCharge;
        while (extraCharge < 0)   {
            cout << "Error, the charge must be at least $0.00. ";
            cout << "What is the shipping and handling charge? ";
            cin >> extraCharge;
        }
    } else {
        extraCharge = 20.95;
    }
    calcShipping(spoolsNum, extraCharge);
}

int main() {
    getOrder();
    // calcShipping(spoolsNum, extraCharge);
    return 0;
}
*/
