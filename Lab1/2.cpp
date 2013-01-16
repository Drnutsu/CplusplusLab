#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int ft=0, inches=0;
    cout<<"This program converts feet and inches to Centimeters.\n";
    cout<<"Enter number of feet: ";
    cin>>ft;
    cout<<"Enter number of inches: ";
    cin>>inches;
    cout<<ft<<"ft "<<inches<<"in = "<<ft*12*2.54+inches*2.54<<"cm";
    return 0;
}
