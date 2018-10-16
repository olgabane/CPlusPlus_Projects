#include <iostream>
using namespace std;
 
class Person
{
public:
	Person():name(NULL){};
	Person(string theName):name(theName){};
	Person(const Person& theObject);
	string getName() const;
	Person& operator=(const Person& rtSide);
	friend istream& operator >>(istream& Instream, Person& personObject);
	friend ostream& operator <<(ostream& outStream, const Person& personObject);
private:
	string name;
};
 
class Vehicle
{
public:
	//constructors
	Vehicle(): man_name(NULL), cylinders(0), owner(0) {};
	Vehicle(string Name, int cyl, Person human): man_name(Name), cylinders(cyl), owner(human) {};
	
	//accessors and mutators
	void setVehicle(string Name, int cyl, Person human);
	void getVehicle() const;
 
protected:
	string man_name;
	int cylinders;
	Person owner;
};
 
class Truck: public Vehicle
{
public:
	//constructors
	Truck(): Vehicle(), tons(0), pounds(0) {};
	Truck(string Name, int cyl, Person human, double ton, int Pound): Vehicle(Name, cyl, human), tons(ton), pounds(Pound){};
	
	//accessors and mutators
	void setTruck(string Name, int cyl, Person human, double ton, int Pound);
	void getTruck() const;
 
protected:
	double tons;
	int pounds;
};
 
int main()
{
	Person John("John");
	Person Olga("Olga");
	Vehicle Vehicle1("Ford", 8, John);
	Truck Truck1("Toyota", 12, Olga, 2, 4000);
	
	cout << "Vehicle1 specs:" << endl;
	Vehicle1.getVehicle();
	cout << "Truck1 specs:" << endl;
	Truck1.getTruck();
	
	cout << "New Truck1 specs:" << endl;
	Truck1.setTruck("Buick", 24, John, 4, 8000);
	Truck1.getTruck();
	
	return 0;
	
};
 
void Vehicle::setVehicle(string Name, int cyl, Person human)
{
	man_name = Name;
	cylinders = cyl;
	owner = human;
};
 
void Vehicle::getVehicle() const
{
	cout << "manufacturer is " << man_name << endl;
	cout << "cylinders is " << cylinders << endl;
	string a = owner.getName();
	cout << "owner is " << a << endl << endl;
};
 
void Truck::setTruck(string Name, int cyl, Person human, double ton, int Pound)
{
	man_name = Name;
	cylinders = cyl;
	owner = human;
	tons = ton;
	pounds = Pound;
};
 
void Truck::getTruck() const
{
	cout << "manufacturer is " << man_name << endl;
	cout << "cylinders is " << cylinders << endl;
	string a = owner.getName();
	cout << "owner is " << a << endl;
	cout << "tons is " << tons << endl;
	cout << "pounds is " << pounds << endl << endl;
};
 
string Person::getName() const
{
	return name;
};
 
//copy constructor
Person::Person(const Person& theObject)
{
	name = theObject.name;
};
 
//oveloaded assignment operator
Person& Person::operator=(const Person& rtSide)
{
	name = rtSide.name;
	return *this;
};
