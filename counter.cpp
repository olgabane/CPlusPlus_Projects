#include <iostream>
using namespace std;

class Counter
{
private:
    int A;
    int B;
    int C;
    int D;
    int count;
    int max;
    
public:
    //constructors
    Counter(int);
    Counter();
    
    void reset();
    void incr1();
    void incr10();
    void incr100();
    void incr1000();
    void getCount();
    bool overflow();
};

int main()
{
    Counter counter(9000);
    char key = {0};
    cout << "Increase cents(a), dimes (s), dollars(d) or tens of dollars (f). Reset (r) counter or exit (e)" << endl;
    do
    {
        cin >> key;
        if(key == 'a')
            counter.incr1();
        else if(key == 's')
            counter.incr10();
        else if(key == 'd')
            counter.incr100();
        else if(key == 'f')
            counter.incr1000();
        else if(key == 'r')
            counter.reset();
        if(counter.overflow() == 0)
        {
            cout << "Counter is now: ";
            counter.getCount();
        }
    }
    while(key != 'e');
    
    return 0;
}

Counter::Counter(int Max)
{
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    count = 0;
    
    if(Max < 9999)
        max = Max;
    else
        max = 9999;
}

Counter::Counter()
{
    cout << "Default constructor" << endl;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    count = 0;
    max = 9999;
}

void Counter::reset()
{
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    count = 0;
}

void Counter::incr1()
{
    if(D < 9)
    {
        D += 1;
    }
    else
    {
        C += 1;
        D = 0;
    }
    
    count = 1000*A + 100*B + 10*C + D;
    
    if(overflow() == 1)
        cout << "Counter reached its limit(" << max <<")" << endl;
    
}

void Counter::incr10()
{
    if(C < 9)
    {
        C += 1;
    }
    else
    {
        B += 1;
        C = 0;
        
    }
    
    count = 1000*A + 100*B + 10*C + D;
    
    if(overflow() == 1)
        cout << "Counter reached its limit(" << max <<")" << endl;
}

void Counter::incr100()
{
    if(B < 9)
    {
        B += 1;
    }
    else
    {
        A += 1;
        B = 0;
    }
    count = 1000*A + 100*B + 10*C + D;
    
    if(overflow() == 1)
        cout << "Counter reached its limit(" << max <<")" << endl;
}

void Counter::incr1000()
{
    A += 1;
    
    count = 1000*A + 100*B + 10*C + D;
    
    if(overflow() == 1)
        cout << "Counter reached its limit(" << max <<")" << endl;
}

void Counter::getCount()
{
    cout << count << endl;
}

bool Counter::overflow()
{
    if(count > max)
    {
        return 1;
    }
    else
        return 0;
}
