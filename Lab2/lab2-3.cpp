#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void initRandSeed();
int randRange(int, int);
int tossDice();

int main()
{
    int d1,d2,dTemp=-1;
    bool firstRound=true;
    initRandSeed();
    d1=tossDice(); //clear first constant output
    while(true)
    {
        d1=tossDice();
        d2=tossDice();
        cout<<"You tossed "<<d1<<", "<<d2<<" = "<<d1+d2<<" dTemp == "<<dTemp<<" isFirst = "<<firstRound<<endl;
        if(d1+d2==7)
        {
            if(firstRound)
                cout<<"You won.\n";
            else
                cout<<"You lose.\n";
            break;
        }
        else if(d1+d2 == 2 || d1+d2 == 3 || d1+d2 == 12)
        {
            if(!firstRound)
                continue;
            cout<<"You lose\n";
            break;
        }
        else
        {
            if(firstRound)
            {
                dTemp=d1+d2;
                firstRound=false;
                continue;
            }
            else
                if(dTemp==d1+d2)
                {
                    cout<<"You won.\n";
                    break;
                }
        }
        firstRound=false;
    }
    return 0;
}
void initRandSeed()
{
    srand((int)time(NULL));
}
int randRange(int low, int high)
{
    double d=rand()/(double)RAND_MAX;
    double s=d*(double)(high-low+1);
    return (int)floor(low+s);
}
int tossDice()
{
    return randRange(1,6);
}
