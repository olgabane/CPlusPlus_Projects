#include <iostream>
using namespace std;

class SalariedEmployee
{
public:
    SalariedEmployee(): salary(0){}
    SalariedEmployee(int Salary): salary(Salary){}
    
    double getSalary() const;
    void setSalary(double newSalary);
    void printCheck() const;
protected:
    double salary;
};

class Administrator: public SalariedEmployee
{
public:
    Administrator(): SalariedEmployee(), annual_salary(), Title(), Responsibility(), Supervisor(){}
    Administrator(int Salary, string title, string responsibility, string supervisor): SalariedEmployee(Salary), annual_salary(Salary*24), Title(title), Responsibility(responsibility), Supervisor(supervisor){}
    
    void setSupervisor(string newname){Supervisor = newname;}
    void setdata();
    void print() const;
    void printCheck() const;
    
private:
    double annual_salary = salary*24;
    string Title;
    string Responsibility;
    string Supervisor;
};

void Administrator::setdata()
{
    string newTitle;
    string newResponsibility;
    double newSalary;
    
    cout << "Title?" << endl;
    cin >> newTitle;
    cout << "Responsibility?" << endl;
    cin >> newResponsibility;
    cout << "Salary?" << endl;
    cin >> newSalary;
    Title = newTitle;
    Responsibility = newResponsibility;
    salary = newSalary;
}

void Administrator::print() const
{
    cout << "\n" << "Administrator Data:" << endl;
    cout << "salary is " << salary << endl;
    cout << "Title is " << Title << endl;
    cout << "Responsibility is " << Responsibility << endl;
    cout << "annual salary is " << salary*24 << endl;
}

void Administrator::printCheck() const
{
    cout << "\n" << "printCheck:" << endl;
    cout << "This is the inherited class " << endl;
    cout << "salary is " << salary << endl;
    cout << "Title is " << Title << endl;
    cout << "Responsibility is " << Responsibility << endl;
    cout << "annual salary is " << annual_salary << endl;
}

void SalariedEmployee::printCheck() const
{
    cout << "\n" << "printCheck:" << endl;
    cout << "This is the base class" << endl;
}

double SalariedEmployee::getSalary() const
{
    double a = salary;
    return a;
}

int main()
{
    Administrator Pam;
    Administrator John(4000, "Associate", "Accounting", "Elena");
    SalariedEmployee Louise(3000);
    
    Pam.setdata();
    
    Pam.print();
    John.print();
    
    int pay;
    pay = Louise.getSalary();
    cout << "Louise's pay is" << pay << endl;
    
    Pam.printCheck();
    John.printCheck();
    
    Louise.printCheck();
    
    return 0;
}
