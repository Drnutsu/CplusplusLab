#include <iostream>
#include <string>

using namespace std;
int findDNAMatch(string s1,string s2,int start=0);
bool isMatched(char a1, char a2)
{
    if( (a1 == 'A' && a2 == 'T') || (a1 == 'T' && a2 == 'A') )
        return 1;
    else if( (a1 == 'C' && a2 == 'G') || (a1 == 'G' && a2 == 'C') )
        return 1;
    return 0;
}
int main()
{
    string input1, input2;
    string t1="ACT";
    string t2="TGA";
    cout<<findDNAMatch(t1,t2);
    /*cout<<"Input main string : ";
    cin>>input1;
    cout<<"Input secondary string : ";
    cin>>input2;*/
    return 0;
}

int findDNAMatch(string s1, string s2, int start)
{
    int i,j;
    string temp = s1.substr(start,s2.length());
    int n = temp.length()-s2.length()+1;
    for(i=0; i<n;i++)
    {
        for(j=0;j<s2.length();j++)
        {
            if(!isMatched(temp[i+j],s2[j]))
            {
                cout<<"unmatched: "<<temp[i+j]<<" "<<s2[j]<<endl;
                continue;
            }
        }
        if(j == s2.length())
            return i;
    }
    return 0;
}
