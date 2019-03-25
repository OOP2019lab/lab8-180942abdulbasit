#include <string>
#include <iostream>
using namespace std;

class Date
{
	friend istream& operator>>(istream& in,Date& d1)
	{
		cout<<endl<<"Date:";
		in>>d1.date;
		cout<<"Month:";
		in>>d1.month;
		cout<<"Year:";
		in>>d1.year;
		if(!(d1.date>0 && d1.date<31 && d1.month>0 && d1.month<13 && d1.year>=1000 && d1.year<=9999))
		{
			d1.date=1;
			d1.month=1;
			d1.year=2000;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const Date& d1)
	{
		out<<" "<<monthNames[d1.month]<<" "<<d1.date<<", "<<d1.year<<endl;
		return out;
	}
private:
	int date;
	int month;
	int year;
	static string monthNames[13];
public:
	Date::Date();
	Date::Date(int,int,int);
	Date& Date::operator+(int);
	Date& Date::operator--();
	Date Date::operator--(int);
	Date& Date::operator= (const Date &);
	int& Date::operator[] (int);
	bool Date::operator==(const Date&);


};