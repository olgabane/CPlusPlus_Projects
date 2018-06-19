// Author: Olga Minkina
// Date: 4/28/18.
// Point.cpp
// Program defines points, calculates radius, distance, theta.
#include <iostream>
#include <math.h>
using namespace std;
 
#define PI 3.14159265
 
struct Points
{
private:
	int X, Y; //position
	float R; //radial distance
	float Theta; //theta = atan(Y/X)
 
public:
//default constructor
	Points();
	
//member functions
void setData(int, int);
float getRadius()const;
void ScalePoint(int);
void getTheta()const;
float Distance(const Points&);
};
 
int main()
{
	Points P1, P2;
	//set cartesian points
	P1.setData(3, 4);
	P2.setData(5, 12);
    //calculate and print radius
	float R_P1 = P1.getRadius();
	cout << "Radius(P1) is " << R_P1 << endl;;
	float R_P2 = P2.getRadius();
	cout << "Radius(P2) is " << R_P2 << endl;
	
	//calculate and print theta
	cout << "Theta values for P1: " << endl;
	P1.getTheta();
	cout << "Theta values for P2: " << endl;
	P2.getTheta();
	
	//scale P1 and P2
	P1.ScalePoint(3);
	P2.ScalePoint(4);
	
	//calculate and print distance between two points
	float x = P1.Distance(P2);
	cout << "Distance between the scaled points is " << x << endl;
	
	return 0;
}
 
Points::Points()
{
	cout << "Default constructor" << endl;
	X = 1;
	Y = 1;
}
 
void Points::setData(int x, int y)
{
	X = x;
	Y = y;
	cout << "Point is (" << X <<", "<<Y << ")" << endl;
}
 
float Points::getRadius()const
{
	float R = sqrt((X*X) + (Y*Y));
	return R;
}
 
void Points::getTheta()const
{
	cout << "Theta = " << atan(Y/X) << endl;
	cout << "Theta in degrees = " << atan(Y/X)*180/PI << "°" << endl;
}
 
void Points::ScalePoint(int S)
{
	X *= S;
	Y *= S;
	cout << "Scaled point is (" << X <<", "<<Y << ")" << endl;
}
 
float Points::Distance(const Points& A)
{
	float R = sqrt(((A.X-X)*(A.X-X))+((A.Y-Y)*(A.Y-Y)));
	return R;
}
