#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 4*atan(1);
double circleArea(double r)
{   return PI*r*r;    }
int main()
{
    double r;
    cout<<"Enter radius: ";
    cin>>r;
    cout<<"Area of circle = "<<circleArea(r);
    return 0;
}
