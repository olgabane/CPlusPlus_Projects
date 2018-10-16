#include <iostream>
using namespace std;
 
class Figure
{
public:
	virtual void erase() const = 0;
	virtual void draw() const = 0;
	void center() const;
};
 
class Triangle: public Figure
{
public:
	void erase() const;
	void draw() const;
};
 
class Rectangle: public Figure
{
public:
	void erase() const;
	void draw() const;
};
 
int main()
{
	Triangle tri;
	tri.draw();
	cout <<
    	"\nDerived class Triangle object calling center().\n\n";
	tri.center();
	
	Rectangle rect;
	rect.draw();
	cout <<
    	"\nDerived class Rectangle object calling center().\n\n";
	rect.center();
	return 0;
	};
 
void Figure::erase() const
{
	cout << "Function erase() called, by calling object Figure" << endl;
};
 
void Triangle::erase() const
{
	cout << "Function erase() called, by calling object Triangle" << endl;
};
 
void Rectangle::erase() const
{
	cout << "Function erase() called, by calling object Rectangle" << endl;
};
 
void Figure::draw() const
{
	cout << "Function draw() called, by calling object Figure" << endl;
};
 
void Triangle::draw() const
{
	cout << "Function draw() called, by calling object Triangle" << endl;
};
 
void Rectangle::draw() const
{
	cout << "Function draw() called, by calling object Rectangle" << endl;
};
 
void Figure::center() const
{
	cout << "Function center() called, by calling object Figure" << endl;
	erase();
	draw();
cout << endl;
};
