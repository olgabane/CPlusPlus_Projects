#include <iostream>
using namespace std;

int main()
{
    char matrix[7][7] = {"0"};
    
    matrix[0][0] = '1';
    matrix[1][0] = '2';
    matrix[2][0] = '3';
    matrix[3][0] = '4';
    matrix[4][0] = '5';
    matrix[5][0] = '6';
    matrix[6][0] = '7';
    
    for(int i = 0; i < 7; i++)
        matrix[i][1] = ' ';
    
    for(int i = 0; i < 7; i++)
        matrix[i][2] = 'A';
    
    for(int i = 0; i < 7; i++)
        matrix[i][3] = 'B';
    
    for(int i = 0; i < 7; i++)
        matrix[i][4] = ' ';
    
    for(int i = 0; i < 7; i++)
        matrix[i][5] = 'C';
    
    for(int i = 0; i < 7; i++)
        matrix[i][6] = 'D';

    
    cout << "Original seating chart" << endl;
    
    for(int row = 0; row < 7; row++)
        {
        for(int column = 0; column < 7; column++)
            {
                cout << matrix[row][column];
            }
        cout << endl;
        }
    
    int seat1;
    char seat2;
    int colfind(0);
    int trial(0);
    
    do{
            do{
            cout << "Desired seat or enter '0A' to exit" << endl;
            cin >> seat1 >> seat2;
            
            if(seat2 == 'A')
            {
                colfind = 2;
            }
            else if(seat2 == 'B')
            {
                colfind = 3;
            }
            else if(seat2 == 'C')
            {
                colfind = 5;
            }
            else if(seat2 == 'D')
            {
                colfind = 6;
            }
            if(matrix[seat1-1][colfind] == 'X')
                cout << "Seat is occupied" << endl;
            }while(matrix[seat1-1][colfind] == 'X');
        
        matrix[seat1-1][colfind] = 'X';
        
        for(int row = 0; row < 7; row++)
        {
            for(int column = 0; column < 7; column++)
            {
                cout << matrix[row][column];
            }
            cout << endl;
        }
        
        trial = 0;
        for(int row = 0; row < 7; row++)
        {
            if(matrix[row][2] == 'X')
                trial ++;
        }
        
        for(int row = 0; row < 7; row++)
        {
            if(matrix[row][3] == 'X')
                trial ++;
        }
        
        for(int row = 0; row < 7; row++)
        {
            if(matrix[row][5] == 'X')
                trial++;
        }
        
        for(int row = 0; row < 7; row++)
        {
            if(matrix[row][6] == 'X')
                trial++;
        }
    
    }while(seat1 != 0 && trial != 28);
    
    cout << "All seats occupied!" << endl;
    return 0;
}
