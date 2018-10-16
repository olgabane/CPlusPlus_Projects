#include <iostream>
using namespace std;

class Payment
{
public:
    //constructors
    Payment(): PayAmt(0){};
    Payment(float payment): PayAmt(payment){};
    
    //mutator and accessor functions
    void setPayAmt(float payment);
    float getPayAmt() const;
    
    void paymentDetails() const;
    
protected:
    float PayAmt;
};

class CashPayment : public Payment
{
public:
    //constructors
    CashPayment() {};
    CashPayment(float payment): Payment(payment){};
    
    //redefined function
    void paymentDetails() const;
};

class CreditCardPayment : public CashPayment
{
public:
    //constructors
    CreditCardPayment(): Name(), expiration_date(0), CC_number(){};
    CreditCardPayment(float payment, string name, string exp, string cc): CashPayment(payment), Name(name), expiration_date(exp), CC_number(cc){};
    
    void paymentDetails() const;
private:
    string Name;
    string expiration_date;
    string CC_number;
};

void Payment::setPayAmt(float payment)
{
    PayAmt = payment;
};

float Payment::getPayAmt() const
{
    return PayAmt;
};

void Payment::paymentDetails() const
{
    cout << "Amount paid is " << PayAmt << endl << endl;
};

void CashPayment::paymentDetails() const
{
    cout << "Amount paid IN CASH is " << PayAmt << endl<<endl;
};

void CreditCardPayment::paymentDetails() const
{
    cout << "Amount paid by credit is " << PayAmt << endl;
    cout << "Name on credit card " << Name << endl;
    cout << "Expiration Date " << expiration_date << endl;
    cout << "Credit card number " << CC_number << endl<<endl;
};


int main()
{
    CashPayment fromSam(12.09);
    CashPayment fromLindsay(17.86);
    CreditCardPayment fromTom(5.60, "Tom Smith", "February 5, 2023", "1234 5678 9123 4567");
    CreditCardPayment fromLex(12.80, "Lex Abrams", "January 20, 2020", "9999 7777 9999 7777");
    
    fromSam.paymentDetails();
    fromLindsay.paymentDetails();
    fromTom.paymentDetails();
    fromLex.paymentDetails();
};
