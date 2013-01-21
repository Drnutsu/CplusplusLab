#include "Date.h"
#include <iostream>

using namespace std;
int main()
{
	Date d1(1,JANUARY,2004);
	Date d2(1,JANUARY,2005);
	cout<<d1<<"\n"<<d2<<endl;
	cout<<d1-d2<<endl;
	return 0;
}