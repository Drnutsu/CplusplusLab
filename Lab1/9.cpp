#include <cstdio>
#include <cmath>
int main()
{
    int isPrime=0;
    for(int i = 10000000;i>=2;i--)
    {
        for(int j=2;j<sqrt(i)+2;j++)
        {
            if(i%j==0)
                break;
            if(j >= sqrt(i)+1)
            {
                isPrime=1;
                break;
            }
        }
        if(isPrime!=0)
        {
            printf("Prime number before 10,000,000 = %d\n",i);
            break;
        }
    }
    return 0;
}
