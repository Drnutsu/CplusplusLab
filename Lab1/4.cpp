#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double balance=0, intr=0;
    cout<<"Interest calculation program\n";
    cout<<"Enter starting balance: ";
    cin>>balance;
    cout<<"Enter annual interest rate: ";
    cin>>intr;
    cout<<setprecision(10);
    cout<<"Balance after one year = "<<balance*(1.00+intr*0.01)<<"\n";
    cout<<"Balance after two year = "<<balance*(1.00+intr*0.01)*(1.00+intr*0.01);
    return 0;
}
