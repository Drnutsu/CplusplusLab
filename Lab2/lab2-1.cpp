#include <iostream>

using namespace std;
bool isPerfect(int);
int sumfaction(int);
int main()
{
    for(int i=1;i<10000;i++)
    {
        if(isPerfect(i))
            cout<<i<<endl;
    }
    return 0;
}
int sumfaction(int n)
{
    int sum=0;
    for(int i=1;i<n;i++)
        sum += ( n%i==0 ) ? i:0;
    return sum;
}
bool isPerfect(int n)
{
    return n == sumfaction(n);
}
