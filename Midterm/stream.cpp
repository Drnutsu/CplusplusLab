#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
void printhead()
{
    cout<<"                     COMPUTER PROGRAMMING 2                 "<<endl
        <<"------------------------------------------------------------"<<endl
        <<setw(10)<<"STUDENT ID"<<"  "<<setw(40)<<left<<"STUDENT NAME"<<"  "<<setw(3)<<"GRADE"<<endl
        <<"------------------------------------------------------------"<<endl;
}
int main()
{
    printhead();
    string str;
    double sumgrade=0;
    int count=0;
    ifstream infile("D:/com_prog2.txt");
    while(!infile.eof())
    {
        getline(infile,str);
        cout<<setw(12)<<left<<str.substr(0,8)
            <<setw(42)<<left<<str.substr(8,40)
            <<setw(3)<<left<<str.substr(48,3)<<endl;
        sumgrade+=atof(str.substr(48,3).c_str());
        count++;
    }
    cout<<"------------------------------------------------------------"<<endl;
    cout<<setw(12)<<" "<<setw(42)<<left<<"GRADE POINT AVERAGE (GPA)"<<setw(4)<<setprecision(2)<<fixed<<sumgrade/count;
    return 0;
}
