#include <iostream>
#include <numeric>
using namespace std;
 
class Rational
{
private:
	int Num;
	int Den;
	
	int numset(int) const;
	int denset(int) const;
	
public:
//constructors
	Rational();
	Rational(int);
	Rational(int, int);
//overloaded member functions
	friend ostream& operator <<(ostream&, const Rational&);
	friend istream& operator >>(istream&, Rational&);
	Rational operator +(Rational&);
	Rational operator -(Rational&);
	Rational operator *(Rational&);
	Rational operator /(Rational&);
	bool operator ==(Rational&);
	bool operator <(Rational&);
	bool operator <=(Rational&);
	bool operator >(Rational&);
	bool operator >=(Rational&);
//function to normalize stored values
	void norm();
};
 
int main()
{
	Rational number1, number2, number3;
	cout <<"Provide rational as fraction for number1" << endl;
	cin >> number1;
	cout << "number1 is " << number1 << endl;
	cout <<"Provide rational as fraction for number2" << endl;
	cin >> number2;
	cout << "number2 is " << number2 << endl;
	number3 = number1+number2;
	number3.norm();
	cout << "Added: " << number3 << endl;
	number3 = number1-number2;
	number3.norm();
	cout << "Subtracted: " << number3 << endl;
	number3 = number1*number2;
	number3.norm();
	cout << "Multiplied: " << number3 << endl;
	number3 = number1/number2;
	number3.norm();
	cout << "Divided: " << number3 << endl;
	if(number1 == number2)
    	cout << "The two fractions are equal" << endl;
	else
     	cout << "The two fractions are unequal" << endl;
	if(number1 < number2)
    	cout << "number1 < number2" << endl;
	else
    	cout << "number1 is not < number2" << endl;
	if(number1 <= number2)
    	cout << "number1 <= number2" << endl;
	else
    	cout << "number1 is not <= number2" << endl;
	if(number1 > number2)
 	   cout << "number1 > number2" << endl;
	else
    	cout << "number1 is not > number2" << endl;
	if(number1 >= number2)
    	cout << "number1 >= number2" << endl;
	else
    	cout << "number1 is not >= number2" << endl;
	
	return 0;
	
}
 
Rational::Rational()
{
	Num = 0;
	Den = 1;
	return;
}
 
Rational::Rational(int A)
{
	Num = A;
	Den = 1;
	return;
}
 
Rational::Rational(int A, int B)
{
	Num = A;
	Den = B;
	return;
}
 
ostream& operator <<(ostream& outs, const Rational& obj)
{
	int num = obj.Num;
	int den = obj.Den;
	outs << num << "/" << den << endl;
	
	return outs;
}
 
istream& operator >>(istream& ins, Rational& obj)
{
	char slash;
	int num;
	int den;
	ins >> num >> slash >> den;
	obj.Num = obj.numset(num);
	obj.Den = obj.denset(den);
	
	return ins;
}
 
int Rational::numset(int A) const
{
	return A;
}
 
int Rational::denset(int B) const
{
	return B;
}
 
Rational Rational::operator +(Rational& rhs)
{
	Rational Temp;
	Temp.Num = (Num * rhs.Den) + (rhs.Num * Den);
	Temp.Den = (Den * rhs.Den);
	return Temp;
}
 
Rational Rational::operator -(Rational& rhs)
{
	Rational Temp;
	Temp.Num = (Num * rhs.Den) - (rhs.Num * Den);
	Temp.Den = (Den * rhs.Den);
	return Temp;
}
 
Rational Rational::operator *(Rational& rhs)
{
	Rational Temp;
	Temp.Num = (Num * rhs.Num);
	Temp.Den = (Den * rhs.Den);
	return Temp;
}
 
Rational Rational::operator /(Rational& rhs)
{
	Rational Temp;
	Temp.Num = (Num * rhs.Den);
	Temp.Den = (Den * rhs.Num);
	return Temp;
}
 
bool Rational::operator ==(Rational& rhs)
{
	if(Num*rhs.Den == Den*rhs.Num)
    	return true;
	else
    	return false;
}
 
bool Rational::operator <(Rational& rhs)
{
	if(Num*rhs.Den < rhs.Num * Den)
    	return true;
	else
    	return false;
}
 
bool Rational::operator <=(Rational& rhs)
{
	if(Num*rhs.Den == Den*rhs.Num || Num*rhs.Den < rhs.Num * Den)
    	return true;
	else
    	return false;
}
 
bool Rational::operator >(Rational& rhs)
{
	if(Num*rhs.Den > rhs.Num * Den)
    	return true;
	else
    	return false;
}
 
bool Rational::operator >=(Rational& rhs)
{
	if(Num*rhs.Den == Den*rhs.Num || Num*rhs.Den > rhs.Num * Den)
    	return true;
	else
    	return false;
}
 
void Rational::norm()
{
	if(Den < 0)
	{
    	Den *= -1;
    	Num *= -1;
	}
	
	int n = std::__gcd(abs(Num), abs(Den));
	Den /= n;
	Num /= n;
	
	return;
}
