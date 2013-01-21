#pragma once
#ifndef _date_h
#define _date_h
#include <string>
#include <sstream>
enum Month { 
	JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, 
	JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER 
};
class Date
{

	int date;
	Month month;
	int year;

	int getDayNum(const Date &date) const;
	Date getDateForm(int dayNum);
	int getLeapYearCount(int inYear) const;
	int getMonthFromDate(int);
public:
	Date(void);
	Date(Month, int, int);
	Date(int, Month, int);
	~Date(void);
	int getDay() const;
	Month getMonth() const;
	int getYear() const;
	std::string toString() const;
	static int dayInMonth(Month, int inYear = 1);
	static bool isLeapYear(int);
	static std::string monthToString(Month);


	friend std::ostream& operator<<(std::ostream &out, const Date &date);

	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator< (const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator> (const Date &other) const;
	bool operator>=(const Date &other) const;

	friend const Date operator+(const Date &date, int n); //r-value
	friend const Date operator-(const Date &date, int n); //r-value
	friend int operator-(const Date &d1, const Date &d2);
	Date& operator+=(int n); //l-value
	Date& operator-=(int n); //l-value
	const Date operator++();
	const Date operator++(int);
	const Date operator--();
	const Date operator--(int);
};

std::string integerToString(int);

#endif