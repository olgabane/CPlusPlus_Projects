// Author: Olga Minkina
// Date: 4/23/18.
// Matrix.cpp
// Program makes weather matrix, adds yearly and monthly rainfall.

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
 
//prototype functions
void RainGen(int**, int, int);
int YearAcc(int*, int);
int MonthAcc(int*, int, int);
 
int main()
{
	int M[5][12];
	int *M_ptr[5];
	int **M_ptr_ptr = &M_ptr[0]; //int pointer to array of pointers
	for(int i = 0; i < 5; ++i) //assign each pointer to point to matrix row
    	{
        	M_ptr[i] = &M[i][0];
    	}
	
	//populate matrix using random number generators
	RainGen(M_ptr_ptr, 5, 12);
	
	cout << "Resulting matrix from the RainGen function:\n" << endl;
	
	//print out matrix
	for(int i = 0; i < 5; ++i)
    	for(int j = 0; j < 12; ++j)
    	{
        	cout <<  setw(3) << M_ptr_ptr[i][j] << " ";
        	if((j+1)%12 == 0)
            	cout << endl;
    	}
	
	//declare int array
	int Year_Acc[5] = {0};
	
	//calculate yearly rainfall
	for(int i = 0; i < 5; ++i)
    	Year_Acc[i] = YearAcc(M_ptr[i], 12);
	
	//print yearly rainfall
	cout << "\nYearly rainfall:\n" << endl;
	for(int i = 0; i < 5; ++i)
    	cout << "Year_Acc[" << i << "] = " << Year_Acc[i] << endl;
	
	//declare int array
	int Month_Acc[12] = {0};
	
	//calculate monthly rainfall
	for(int i = 0; i < 12; ++i)
    	Month_Acc[i] = MonthAcc(M_ptr[0]+i, 5, 12);
	
	//print monthly rainfall
	cout << "\nMonthly rainfall:\n" << endl;
	for(int i = 0; i < 12; ++i)
    	cout << "Month_Acc[" << i << "] = " << Month_Acc[i] << endl;
	
	return 0;
}
 
void RainGen(int **M_ptr_ptr, int R, int C)
{
	//seed random number generator
	srand(43);
	
	//populate array
	for(int i = 0; i < R; ++i)
     	for(int j = 0; j < C; ++j)
        	{
                M_ptr_ptr[i][j] = rand()%100;
        	}
	return;
	
}
 
int YearAcc(int *M_ptr, int C)
{
	int sum(0);
	for(int i = 0; i < C; ++i)
    	{
        	sum += *M_ptr;
        	M_ptr++;
    	}
	return sum;
}
 
int MonthAcc(int *M_ptr, int C, int R)
{
	int sum(0);
	for(int i = 0; i < C; ++i)
	{
    	sum += *M_ptr;
    	M_ptr += 12;
	}
	return sum;
}

