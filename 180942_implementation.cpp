#include "180942_header.h"
#include <iostream>
using namespace std;

string Date::monthNames[13] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};

Date::Date()  //default constructor
{
	date=1;
	month=1;
	year=2000;
}
Date::Date(int b,int a,int c) //overloaded constructor in format (month, date,year)
{
	if(a>0 && a<31 && b>0 && b<13 && c>=1000 && c<=9999)
	{
		date=a;
		month=b;
		year=c;
	}
	else
	{
		date=1;
		month=1;
		year=2000;
	}
}
Date& Date::operator+(int a) //increases the date by a
{
	date=date+a;
	if(date>30)
	{
		date=date-30;
		month++;
		if(month>12)
		{
			month=1;
			year++;
		}
	}
	return *this;
}
Date& Date::operator=(const Date &d)  //make this date equal to other 
{
	date=d.date;
	month=d.month;
	year=d.year;
	return *this;
}
Date& Date::operator--()  //pre decrement operator overloading
{
	date=date--;
	if(date<1)
	{
		date=date+30;
		month=month--;
		if(month<1)
		{
			month=month+12;
			year=year--;
		}
	}
	return *this;
}
Date Date::operator--(int a)  //post decrement operator overloading
{
	Date temp=*this;
	date=date--;
	if(date<1)
	{
		date=date+30;
		month=month--;
		if(month<1)
		{
			month=month+12;
			year=year--;
		}
	}
	return temp;
}
int& Date::operator[] (int a)  //overloading subscript operator
{
	if(a==0)
		return date;
	else if(a==1)
		return month;
	else if(a==2)
		return year;
	else 
		cout<<"Index can only be 0, 1 or 2"<<endl;
	return date;
}
bool Date::operator==(const Date& d1)  //overloading the equality operator ... returns true if two dates are equal
{
	if (date==d1.date && month==d1.month && year==d1.year)
		return true;
	return false;
}
