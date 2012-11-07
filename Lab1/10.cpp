#include <iostream>

using namespace std;

int pow(int a,int r)
{
    int temppow=a;
    for(int i=1;i<r;i++)
    {
        a*=temppow;
    }
    return a;
}

int main()
{
    int n,temp,tempd,digits;
    cout<<"This program prints the number with comma.\n";
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The result is ";

    temp=n;
    for(digits=0;temp!=0;digits++)
        temp/=10;
    tempd=digits;
    if(n<0)
    {
        cout<<"-";
        n=-n;
    }
    for (int i = digits; i >= 1; i--)
    {
        if(i%3==0 && (digits%3!=0 || i!=digits) )
            cout<<",";
        if(i==1) //last digit
        {
            n-=( n/pow(10,tempd-1) )*pow(10,tempd-1);
            cout<<n;
        }
        else
        {
            cout<<n/pow(10,tempd-1);
            n-=( n/pow(10,tempd-1) )*pow(10,tempd-1);
        }
        tempd--;
    }
    return 0;
}
