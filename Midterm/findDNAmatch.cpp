#include <iostream>
#include <string>
using namespace std;
int findDNAMatch(string s1, string s2, int start=0);
int main()
{
    int start = 0;
    string str1, str2;
    cout<<"input str1 :";
    getline(cin,str1);
    cout<<"input str2 :";
    getline(cin,str2);
    cout<<"input start [default = 0] :";
    cin>>start;
    cout<<findDNAMatch(str1,str2,start);
    return 0;
}

int findDNAMatch(string s1, string s2, int start)
{
    string &lstr = s1.size()>s2.size()?s1:s2;
    string &sstr = s1.size()>s2.size()?s2:s1;
    lstr = lstr.substr(start,lstr.size()-start);
    for(auto &i : sstr)
    {
        if(i == 'A')        i='T';
        else if(i == 'T')   i='A';
        else if(i == 'C')   i='G';
        else if(i == 'G')   i='C';
        else    cout<<"error"<<endl;
    }
    if(lstr.find(sstr)!=string::npos)
        return start+(int)lstr.find(sstr);
    else
        return -1;
}
