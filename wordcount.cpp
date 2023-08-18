#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
    cout<<"Program to count number of words given in a file"<<endl;
    cout<<" Devloped by Prashant Kumar"<<endl;
    ifstream inFile; 
    string fileName;
    string s;
    int count = 0;

    cout << "enter the file name:- "<<endl;
    getline(cin,fileName);
    inFile.open(fileName.c_str());

    while(!inFile.eof())
    {               
        inFile>>s; 
        count++;
    }

    cout <<"The Total Number of words in the file is:- "<<count<<endl;
    cout<<"thanks for using the program"<<endl;
    inFile.close();

    cin.get();  
    return 0;
}
