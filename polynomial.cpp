#include <iostream>
#include <cmath>
using namespace std;
 
class Poly{
private:
	int order;  //order of polynomial
	int *coeff; //pointer to array of coeff on heap
	
public:
	Poly(); //default constructor
	Poly(int, int = 1); //parameterized constructor; used to set P3
 
	Poly(int, int*);
	//destructor
	~Poly();
	//copy constructor
	Poly(const Poly &);
	void operator=(const Poly&);
	
	//mutators and accessors
	void set(); //query for coefficient values
	void set(int coeff[], int size); //input coeffs via external coeff vector
	int getOrder()const; //get order of poynomial
	int* get(); //return pointer to coeff array
	void printt();
	
	//overloaded operators
	Poly operator +(const Poly &rhs);
	Poly operator -(const Poly &rhs);
	Poly operator *(const Poly &rhs);
	Poly operator *(const int);
	bool operator ==(const Poly &rhs);
	int & operator[](int I);
	int operator()(int S);
	
	friend Poly operator*(int, const Poly &);
	
};
 
int main()
{
	//declare three polynomial objects
	Poly P1, P2;
	
	//set order and coefficients of polynomials
	P1.set();
	P2.set();
	
	//declare P3 and allocated memory (enough for P1*P2)
	int ord1 = P1.getOrder();
	int ord2 = P2.getOrder();
	Poly P3(ord1+ord2);
	
	P3 = P1 + P2;
	cout << "P1 + P2: " << endl;
	P3.printt();
 
	P3 = P2 - P1;
	cout << "P2 - P1: " << endl;
	P3.printt();
 
	P3 = P1 * P2;
	cout << "P1 * P2: " << endl;
	P3.printt();
	
	P3 = P1 * 10;
	cout << "P1 * 10: " << endl;
	P3.printt();
	
	P3 = 10 * P1;
	cout << "10 * P1: " << endl;
	P3.printt();
	
	cout << "Does P1 == P2?" << endl;
	if(P1 == P2)
    	cout << "The two polynomials are equal!" << endl;
	else
    	cout << "The two polynomials are not equal!" << endl;
	
	P1[3] = P2[5];
	cout << "P1[3] = P2[5], resulting P1 is: " << endl;
	P1.printt();
	
	int Z = P1(5);
	cout << "P1(5) is " << Z << endl;
	
	return 0;
}
 
Poly::Poly()
{
	order = 0;
	//allocate memory
	coeff = new int[order];
	coeff[0] = 1;
}
 
Poly::Poly(int ord, int p)
{
	order = ord;
	//allocate memory
	coeff = new int[ord+2];
	for(int i = 0; i < ord+1; ++i)
    	coeff[i] = p;
}
 
void Poly::set()
{
	cout << "Input order:" << endl;
	cin >> order;
	
	//allocate memory
	coeff = new int[order+1];
	cout << "Input coefficients:" << endl;
	for(int i = 0; i < order+1; ++i)
    	cin >> coeff[i];
}
 
int* Poly::get()
{
	return coeff;
}
 
int Poly::getOrder()const
{
	return order;
}
 
void Poly::printt()
{
	for(int i = order; i > 1; --i)
	{
    	{
    	if(coeff[i-1] >= 0 && coeff[i] != 0)
        	cout << coeff[i] << "X^" << i << " + ";
    	else if(coeff[i-1] < 0 && coeff[i] != 0)
        	cout << coeff[i] << "X^" << i << " ";
    	}
	}
	
	if(coeff[1] != 0)
    	cout << coeff[1] << "X";
	if(coeff[0] != 0)
    	{
    	if(coeff[0] > 0)
        	cout << " + " << coeff[0];
    	else if(coeff[0] < 0)
        	cout << coeff[0];
    	else
        	cout <<"";
    	}
	
	cout << endl;
 	
}
 
Poly Poly::operator +(const Poly &rhs)
{
	int newOrder = max(order, rhs.order);
	Poly temp(newOrder);
	
	//need to set remaining coefficients to 0 of "shorter" polynomial
	for(int i = 1; i < order + 1; ++i)
    	rhs.coeff[rhs.order+i] = 0;
	for(int i = 1; i < rhs.order + 1 ; ++i)
    	coeff[order+i] = 0;
	
	for(int i = 0; i < newOrder+1; ++i)
    	temp.coeff[i] = coeff[i] + rhs.coeff[i];
	temp.order = newOrder;
 
	return temp;
}
 
Poly Poly::operator -(const Poly &rhs)
{
	int newOrder = max(order, rhs.order);
	Poly temp(newOrder);
 
	for(int i = 0; i < newOrder+1; ++i)
        	temp.coeff[i] = coeff[i] - rhs.coeff[i];
	temp.order = newOrder;
 
	return temp;
}
 
Poly Poly::operator *(const Poly &rhs)
{
	int ord2 = rhs.getOrder();
	Poly temp(ord2+order);
 
	for(int i = 0; i < temp.order + 1; ++i)
    	temp.coeff[i] = 0;
	
	for(int i = 0; i < order+1; i++)
	{
    	for(int j = 0; j < ord2+1; j++)
    	{
        	temp.coeff[i+j] = temp.coeff[i+j] + (coeff[i] * rhs.coeff[j]);
    	}
	}
	
	return temp;
}
 
void Poly::operator=(const Poly& M)
{
	order = M.order;
	
	for(int i = 0; i < order + 1; ++i )
    	coeff[i] = M.coeff[i];
}
 
Poly::Poly(const Poly & Poly_copy)
{
 	order = Poly_copy.order;
	coeff = new int[order+1];
	coeff = Poly_copy.coeff;
}
 
 Poly::~Poly()
 {
	delete[] coeff;
 }
 
Poly Poly::operator *(const int R)
 
{
	Poly temp(order);
	for(int i = 0; i < order + 1; ++i )
    	temp.coeff[i] = coeff[i]*R;
	return temp;
	
};
 
bool Poly::operator ==(const Poly & rhs)
{
	bool flag = 0;
	
	//if orders do not equal, then polynomials are not equal.
	if(order != rhs.order)
    	flag = 0;
 
	else if(order == rhs.order)
    	{
    	for(int i = 0; i < order + 1; ++i )
        	if(coeff[i] != rhs.coeff[i])
            	flag = 1;
    	}
	
	return flag;
};
 
int & Poly::operator[](int I)
{
	return coeff[I];
};
 
int Poly::operator()(int S)
{
	int sum = 0;
	
	for(int i = 0; i < order+1; ++i )
    	sum += coeff[i]*pow(S, i);
	return sum;
};
 
//NOTE: this function is not a member function!!
Poly operator *(int R, const Poly & Poly_copy)
{
	Poly temp(Poly_copy.order);
	for(int i = 0; i < Poly_copy.order + 1; ++i )
    	temp.coeff[i] = Poly_copy.coeff[i]*R;
	return temp;
};
