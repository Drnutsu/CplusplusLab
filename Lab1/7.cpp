//Time Complexity == O(n)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int input=0, fmax=INT_MIN, smax=INT_MIN+1;
    int pfmax,psmax;
    vector<int> buffer(10);
    cout<<"This program finds the two largest integers in a list.\n";
    cout<<"Enter values, one per line, using a 0 to signal the end of the list.\n";

    while(1)
    {
        cout<<"? ";
        cin>>input;
        if(input == 0)
            break;
        buffer.push_back(input);
    }
    for(int i=0;i<buffer.size();i++)
    {
        if(buffer[i]>fmax)
        {
            fmax=buffer[i];
            pfmax=i;
        }
    }
    for(int i=0;i<buffer.size();i++)
    {
        if(i == pfmax)
            continue;
        if(buffer[i]>smax)
        {
            smax=buffer[i];
            psmax=i;
        }
    }
    cout<<"The largest value is "<<buffer[pfmax]<<"\n";
    cout<<"The second largest value is "<<buffer[psmax]<<"\n";
    return 0;
}
