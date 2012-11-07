#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a, b, c;
    cout<<"This program finds whether three numbers are right triangle sides.\n";
    cout<<"Enter values, one per line.\n";
    cout<<"? ";
    cin>>a;
    cout<<"? ";
    cin>>b;
    cout<<"? ";
    cin>>c;
    if( a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
        cout<<"These numbers are right triangle sides.\n";
    else
        cout<<"These numbers aren't right triangle sides.\n";

    return 0;
}
