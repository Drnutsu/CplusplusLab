#include <iostream>
#include <string>
using namespace std;
bool endsWith(string str, string suffix)
{
    string cmp = str.substr(str.length()-suffix.length() ,suffix.length());
    return cmp == suffix;
}
int main()
{
    string str1("Hello, world");
    string str2("orl");
    cout<<str1<<(endsWith(str1,str2)?" is":" isn't")<<" ends with "<<str2<<endl;
    return 0;
}
