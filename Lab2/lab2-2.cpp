#include <iostream>
#include <cmath>

using namespace std;
bool isPrime(int n)
{
    if(n<2)
        return false;
    if( n == 2 )
        return true;
    for(int i=2; i<(int)sqrt(n)+1; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    for(int i=1;i<=100;i++)
    {
        if(isPrime(i))
            cout<<i<<endl;
    }
    return 0;
}
