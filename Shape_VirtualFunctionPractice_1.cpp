#include <iostream>
using namespace std;
 
class Figure
{
public:
	void erase() const;
	void draw() const;
};
 
class Triangle: public Figure
{
public:
	void erase() const;
	void draw() const;
	void center() const;
};
 
class Rectangle: public Figure
{
public:
	void erase() const;
	void draw() const;
	void center() const;
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
 
void Triangle::center() const
{
	erase();
	draw();
	cout << "Function center() called, by calling object Triangle" << endl << endl;
};
 
void Rectangle::center() const
{
	erase();
	draw();
	cout << "Function center() called, by calling object Rectangle" << endl << endl;
};
