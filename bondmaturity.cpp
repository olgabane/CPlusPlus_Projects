#include <iostream>
#include <cstring>
using namespace std;
 
class Date{
private:
	int day, month, year;
	static int daysMonth[12];
	static int monthsYear;
	
public:
	//constructors
	Date():day(1), month(1), year(1){}
	Date(int Day, int Month, int Year): day(Day), month(Month), year(Year){}
	
	//mutators and accessors
	int getDay();
	int getMonth();
	int getYear();
	
	//calculate the number of days between
	int calcDiff(const Date & Today);
};
 
class Bond{
private:
	char * name; //name of bond
	float value;
	Date purchaseDate;
	Date maturityDate;
	Date Today;         	//class within class
	
public:
	//constructors & use initialization list
	Bond(): name(NULL), value(0.0), purchaseDate(0,0,0), maturityDate(0, 0, 0){}
	Bond(char *Name, float Value, Date d1, Date d2, Date d3): name(Name), value(Value), purchaseDate(d1), maturityDate(d2), Today(d3){
    	name = new char[strlen(Name)];
    	for(int i = 0; i < strlen(Name); ++i)
    	{
        	name[i] = Name[i];
    	}
	}
	
	//destructors
	~Bond(){delete []name;} 
	
	//Accessor and mutator functions
	void display();
	
	// Methods
	int CalcDaysMaturity(Date & hoy);
	
};
 
int Date::monthsYear = 12;
int Date::daysMonth[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};
 
int main()
{
	Date Today(18,4,2012);
	Date Purchase(28, 2, 2012);
	Date Maturity(31, 12, 2025);
	Bond Y("NYC Obligation", 885.0, Purchase, Maturity, Today);
	Y.display();
	int days = Y.CalcDaysMaturity(Today);
	cout << "Days to maturity: " << days <<endl;
	Bond *bond_ptr = new Bond("GW_Bridge_Obligation", 895.0, Purchase, Maturity, Today);
	bond_ptr -> display();
	delete bond_ptr;
	
	return 0;
}
 
int Date::getDay()
{
	return day;
}
 
int Date::getMonth()
{
	return month;
}
 
int Date::getYear()
{
	return year;
}
 
int Date::calcDiff(const Date & Today)
{
	int days_in_year = 0;
	int sum = 0;
	for(int i = 0; i < 12; ++i)
    	days_in_year += daysMonth[i];
	
	//account for full years inbetween
	sum = ((days_in_year)*(abs(year - Today.year)-1));
	
	//account for full months
	
	int days_in_month1 = 0;
	for(int i= 0; i < month-1; ++i)
    	days_in_month1 += daysMonth[i];
	
	int days_in_month2 = 0;
	for(int i= Today.month+1; i < 12; ++i)
    	days_in_month2 += daysMonth[i];
	
	//account for days mid month
	int day1 = day;
	
	int day2 = daysMonth[month-1] - Today.day;
	
	sum = sum + days_in_month1 + days_in_month2 + day1 + day2;
	
	return sum;
};
 
void Bond::display()
{
	cout << "Name of bond is '" << name << "'" << endl;
	cout << "Value is " << value << endl;
	cout << "Purchase date is " << purchaseDate.getMonth() << "/" << purchaseDate.getDay() << "/" << purchaseDate.getYear() << endl;
	cout << "Maturity date is " << maturityDate.getMonth() << "/" << maturityDate.getDay() << "/" << maturityDate.getYear() << endl;
    cout << "Today date is " << Today.getMonth() << "/" << Today.getDay() << "/" << Today.getYear() << endl;
}
 
int Bond::CalcDaysMaturity(Date & Today)
{
	int sum = maturityDate.calcDiff(Today);
	return sum;
}
