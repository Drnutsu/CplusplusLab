#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string capitalize(string);
string capitalizeEachWord(string);

int main()
{
    string str="caN i hAz cHEezBergeR?";
    cout<<"\""<<str<<"\" capitalizes to \""<<capitalizeEachWord(str)<<"\""<<endl;
    return 0;
}

string capitalize(string str)
{
    for(string::iterator it=str.begin();it<str.end();it++)
    {
        if(it == str.begin())
            *it=toupper(*it);
        else
            *it=tolower(*it);
    }
    return str;
}
string capitalizeEachWord(string str)
{
    for(string::iterator it=str.begin();it<str.end();it++)
    {
        if(it == str.begin() || *(it-1) == ' ')
            *it=toupper(*it);
        else
            *it=tolower(*it);
    }
    return str;
}

