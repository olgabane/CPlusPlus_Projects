#include <iostream>
#include <iomanip>
using namespace std;
 
class matrix{
private:
	int **p, m, n;
public:
	//default constructor
	matrix();
	//parameterized constructor
	matrix(int row, int col);
	
	//destructor and copy assignment operator
	~matrix();
	matrix(const matrix&);
	
	//operators
	matrix operator +(matrix);
	matrix operator -(matrix);
	matrix operator *(int);
	bool operator ==(matrix);
	void operator=(const matrix&);
	
	void accept();
	
	void display();
};
 
int main()
{
	matrix X1(10, 5), X2(10, 5), X3(10, 5);
	
	X1.accept();
	cout << "\nX1 ";
	X1.display();
	X2.accept();
	cout << "\nX2 ";
	X2.display();
	X3 = X1 + X2;
	cout << "\nX1 + X2 ";
	X3.display();
	X3 = X2 - X1;
	cout << "\nX2 - X1 ";
	X3.display();
	X3 = X1 * 10;
	cout << "\nX1 * 10 ";
	X3.display();
	X3 = X1;
	cout << "\nX3 = X1 ";
	X3.display();
	
	cout << "\nCompare X3 and X2:" << endl;
	if(X3 == X2)
    	cout << "The two matrices are identical" << endl;
	else
    	cout << "The two matrices are different" << endl;
	cout << "\nCompare X3 and X1:" << endl;
	if(X3 == X1)
    	cout << "The two matrices are identical" << endl;
	else
    	cout << "The two matrices are different" << endl;
	
	return 0;
}
 
matrix::matrix()
{
	m = 0;
	n = 0;
}
 
matrix::matrix(int row, int col)
{
	m = row;
	n = col;
	p = new int *[m]; //allocated array of pointers of length m
                  	//p is pointer pointing to array of pointers
	for(int i = 0; i < m; i++)
    	p[i] = new int[n];
}
 
matrix::~matrix()
{
	for(int i = 0; i < m; i++)
    	delete[] p[i];
	delete []p;
}
 
void matrix::accept()
{
	int value = 0;
	cout << "\nChoose start value for matrix" << endl;
	cin >> value;
	
	for(int i = 0; i < m; ++i)
    	for(int j = 0; j < n; ++j)
        	{
            	p[i][j] = value;
            	value++;
        	}
	
}
 
void matrix::display()
{
	cout << "resulting matrix:" << endl;
	
	for(int i = 0; i < m; ++i)
    	{
    	cout<< endl;
    	for(int j = 0; j < n; ++j)
        	cout << setw(3) << p[i][j] << " ";
    	}
	cout << endl;
}
 
matrix matrix::operator+(matrix M)
{
	matrix temp(m,n);
	
	for(int i = 0; i < m; ++i)
    	for(int j = 0; j < n; ++j)
        	temp.p[i][j] = p[i][j] + M.p[i][j];
	return temp;
}
 
matrix matrix::operator-(matrix M)
{
	matrix temp(m,n);
	
	for(int i = 0; i < m; ++i)
    	for(int j = 0; j < n; ++j)
        	temp.p[i][j] = p[i][j] - M.p[i][j];
	return temp;
}
 
matrix::matrix(const matrix& M)
{
	m = M.m;
	n = M.n;
	
	p = new int *[m];
	for(int i = 0; i < m; i++)
    	p[i] = new int[n];
	
	for(int i = 0; i < m; ++i)
    	for(int j = 0; j < n; j++)
        	p[i][j] = M.p[i][j];
}
 
void matrix::operator=(const matrix &M)
{
 
	for (int i=0; i<m; i++)
    	for (int j =0; j<n; j++)
        	p[i][j]= M.p[i][j];
}
 
matrix matrix::operator*(int x)
{
	matrix temp(m,n);
	
	for(int i = 0; i < m; ++i)
    	for(int j = 0; j < n; ++j)
        	temp.p[i][j] = p[i][j] * x;
	return temp;
}
 
bool matrix::operator ==(matrix M)
{
	int y = 0;
	for(int i = 0; i < m; ++i)
    	for(int j = 0; j < n; ++j)
        	if(p[i][j] != M.p[i][j])
        	{
            	y++;
        	}
	if(y == 0)
    	return true;
	else
    	return false;
}
