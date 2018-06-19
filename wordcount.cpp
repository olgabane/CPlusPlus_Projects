#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;
 
int main()
{
	char str[101];
	
	do
	{
	int counter = 0;
	int array[26] = {0};
	int space(0), comma(0), period(0);
    	
	cout << "Provide string or # to exist:" << endl;
	cin.getline(str, 100);
	
	for(int i = 1; i < strlen(str); ++i)
    	if(isspace(str[i]))
        	counter++;
    	
	cout << counter+1 << " words" << endl;
	
	for(int i = 0; i < strlen(str); ++i)
    	for(int j = 97; j < 122; j++)
        	if(str[i] == j || str[i] == j-32)
            	array[j-97]++;
    	
	for(int i = 0; i < strlen(str); ++i)
    	{
    	if(str[i] == 32)
        	space++;
    	if(str[i] == 44)
       	comma++;
    	if(str[i] == 46)
       	period++;
    	}
       	
	for(int j = 0; j < 26; j++)
    	if(array[j] != 0)
        	{
        	char a = j+97;
        	cout << array[j] << " " << a << endl;
        	}
	
	if(space != 0)
    	cout << space << "  " << endl;
	if(comma != 0)
    	cout << comma << " ," << endl;
	if(period != 0)
    	cout << period << " ." << endl;
 
 
	}while(str[0] != '#');
	
	return 0;
}
