#include <iostream>
#include <cstdint>
#define BUFFER_SIZE 16
#define LASTFIB BUFFER_SIZE-1
using namespace std;
int64_t fib(int n,int64_t *buffer)
{
    if(buffer[n]!=0)
        return buffer[n];
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;
    else
    {
        buffer[n]=fib(n-1,buffer)+fib(n-2,buffer);
        return buffer[n];
    }
}
int64_t fib(int n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
int main()
{
    int64_t buffer[BUFFER_SIZE]={0};
    for(int i=0; i<=LASTFIB; i++)
    {
        if(i>=2)
            cout<<"F"<<i<<" = "<<fib(i,buffer)<<" ("<<fib(i-2,buffer)<<"+"<<fib(i-1,buffer)<<")\n";
        else
            cout<<"F"<<i<<" = "<<fib(i,buffer)<<"\n";
    }
    /*for(int i=0; i<=LASTFIB; i++)
    {
        if(i>=2)
            cout<<"F"<<i<<" = "<<fib(i)<<" ("<<fib(i-2)<<"+"<<fib(i-1)<<")\n";
        else
            cout<<"F"<<i<<" = "<<fib(i)<<"\n";
    }*/
    return 0;
}
