#include "Date.h"
#include <iostream>
#include <cstdlib>
std::string integerToString(int n)
{
	std::stringstream ss;
	ss<<n;
	return ss.str(); 
}

// default ctor
Date::Date(void) : date(1), month(JANUARY), year(2000)
{
}
// d-m-y ctor
Date::Date(int inDate, Month inMonth, int inYear) : date(inDate), month(inMonth), year(inYear)
{
}
// m-d-y ctor
Date::Date(Month inMonth, int inDate, int inYear) : date(inDate), month(inMonth), year(inYear)
{
}
// dtor
Date::~Date(void)
{
}

// getter member functions section.
int Date::getDay() const
{
	return this->date;
}
Month Date::getMonth() const
{
	return this->month;
}
int Date::getYear() const
{
	return this->year;
}

// toString function
std::string Date::toString() const
{
	std::string str;
	switch (Date::month)
	{
	case JANUARY:
		str+="Jan";
		break;
	case FEBRUARY:
		str+="Feb";
		break;
	case MARCH:
		str+="Mar";
		break;
	case APRIL:
		str+="Apr";
		break;
	case MAY:
		str+="May";
		break;
	case JUNE:
		str+="Jun";
		break;
	case JULY:
		str+="Jul";
		break;
	case AUGUST:
		str+="Aug";
		break;
	case SEPTEMBER:
		str+="Sep";
		break;
	case NOVEMBER:
		str+="Nov";
		break;
	case DECEMBER:
		str+="Dec";
		break;
	default:
		std::cerr<<"internal error occured\n";
		break;
	}
	return integerToString(date)+"-"+str+"-"+integerToString(year);
}
// utility functions section.

bool Date::isLeapYear(int inYear)
{
	return (inYear%400 == 0) && !(inYear%100 !=0) || (inYear%4 == 0 && inYear%100 !=0);
}
int Date::dayInMonth(Month inMonth, int inYear)
{
	return 31-(inMonth==2?(3-Date::isLeapYear(inYear)):((inMonth-1)%7)%2);
}

std::string Date::monthToString(Month inMonth)
{
	switch (inMonth)
	{
	case JANUARY:
		return "JANUARY";
	case FEBRUARY:
		return "Febuary";
	case MARCH:
		return "MARCH";
	case APRIL:
		return "APRIL";
	case MAY:
		return "MAY";
	case JUNE:
		return "JUNE";
	case JULY:
		return "JULY";
	case AUGUST:
		return "AUGUST";
	case SEPTEMBER:
		return "SEPTEMBER";
	case OCTOBER:
		return "OCTOBER";
	case NOVEMBER:
		return "NOVEMBER";
	case DECEMBER:
		return "DECEMBER";
	default:
		std::cerr<<"internal error occured\n";
		return 0;
		break;
	}
}

// overloading operator section.
// comparator operators.

std::ostream& operator<<(std::ostream &out, const Date &date)
{
	return out<<date.toString();
}
bool Date::operator==(const Date &other) const
{
	return this->getDay()==other.getDay() && this->getMonth()==other.getMonth() && this->getYear()==other.getYear();
}
bool Date::operator!=(const Date &other) const
{
	return *this==other;
}
bool Date::operator<(const Date &other) const
{
	return this->getYear() < other.getYear() || (this->getYear() == other.getYear() && this->getMonth() < other.getMonth()) 
		|| (this->getYear() == other.getYear() && this->getMonth() == other.getMonth() && this->getDay() < other.getDay());
}
bool Date::operator<=(const Date &other) const
{
	return *this<other || *this == other;
}
bool Date::operator>(const Date &other) const
{
	return !(*this <= other);
}
bool Date::operator>=(const Date &other) const
{
	return !(*this < other);
}

// internal tool functions
int Date::getLeapYearCount(int inYear) const
{
	int count = 0;
	for(int i=1;i<=inYear;i++)
		count+=isLeapYear(i);
	return count;
}

int Date::getDayNum(const Date &date) const
{
	int totalDate = 0;
	totalDate += date.getYear()*365 + date.getLeapYearCount(date.getYear()-1);
	for(int i = 1; i<=int(date.getMonth()); i++)
		totalDate += date.dayInMonth(Month(i),date.getYear());
	totalDate += date.getDay();
	return totalDate;
}

Date Date::getDateForm(int inDay)
{
	Date date;
	int count = 1;
	date.year = int(inDay/365.2425);
	inDay-=int(date.year*365.2425);
	while(true)
	{
		if( inDay-Date::dayInMonth(Month(count), date.year) >= 0)
		{
			inDay-=Date::dayInMonth(Month(count), date.year);
			count++;
		}
		else
			break;
	}
	date.month = Month(count);
	date.date = inDay;
	return date;
}

// compound assignment operators
Date& Date::operator+=(int n)
{
	int totalDay;
	totalDay = this->getDayNum(*this)+n;
	this->getDateForm(totalDay);
	return *this;
}
Date& Date::operator-=(int n)
{
	int totalDay;
	totalDay = this->getDayNum(*this)-n;
	this->getDateForm(totalDay);
	return *this;
}
// binary arithmetic operators.
const Date operator+(const Date &date, int n)
{
	Date newDate(date);
	newDate+=n;
	return newDate;
}
const Date operator-(const Date &date, int n)
{
	Date newDate(date);
	newDate-=n;
	return newDate;
}
int operator-(const Date &d1, const Date &d2)
{
	return abs(d1.getDayNum(d1) - d2.getDayNum(d2));
}