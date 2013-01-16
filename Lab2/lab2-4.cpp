#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void initRandSeed();
int randRange(int, int);
int tossDice();
int playDice();
int main()
{
    initRandSeed();
    int dump=randRange(1,100);
    int wincount=0;
    int sample=5000;
    for(int i=0;i<sample;i++)
        wincount+=playDice();
    cout<<"Winning "<<wincount<<" out of "<<sample<<endl;
    cout<<"Probability is "<<(double)wincount/sample*100<<"%.\n";
    return 0;
}
void initRandSeed()
{
    static bool initialized=false;
    if(!initialized)
    {
        srand((int)time(NULL));
        initialized=true;
    }
}
int randRange(int low, int high)
{
    double d=rand()/((double)1+(double)(RAND_MAX));
    double s=d*(double)(high-low+1);
    return (int)floor(low+s);
}
int tossDice()
{
    return randRange(1,6);
}
int playDice()
{
    int d1,d2,dTemp=-1;
    bool firstRound=true;
    initRandSeed();
    d1=tossDice(); //clear first constant output
    while(true)
    {
        d1=tossDice();
        d2=tossDice();
        //cout<<"You tossed "<<d1<<", "<<d2<<" = "<<d1+d2<<" dTemp == "<<dTemp<<" isFirst = "<<firstRound<<endl;
        if(d1+d2==7)
        {
            if(firstRound)
                return 1;//cout<<"You won.\n";
            else
                return 0;//cout<<"You lose.\n";
            //break;
        }
        else if(d1+d2 == 2 || d1+d2 == 3 || d1+d2 == 12)
        {
            if(!firstRound)
                continue;
            return 0;//cout<<"You lose\n";
            //break;
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
                    return 1;//cout<<"You won.\n";
                    //break;
                }
        }
        firstRound=false;
    }
}
