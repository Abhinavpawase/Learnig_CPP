
#include <iostream>
#include <string>

using namespace std;

class Quote;
class Discount_Quote;

void    Function_1();
void    Print_Price(const Quote&);

int main()
{
    Function_1();
}

class Quote {

protected:

    double price;

    Quote() = default;

    Quote(double Price) {
        price = Price;
    }

    string isbn;

public:

    string owner;

    virtual double net_price() const {
        return price;
    };

    double seller_price() {
        return 0.9 * price;
    }

};

class Discount_Quote : public Quote {

public:

    Discount_Quote() = default;

    Discount_Quote(double Price) {
        price = Price;
    }

    int discount_percentage = 15;

    double net_price() const override {
        double discounted_price = price - (price * discount_percentage) / 100;
        return (discounted_price);
    }

};

void Function_1() {

    /*Quote _Quote(150);

    Print_Price(_Quote);*/

    Discount_Quote _Quote2(250) ;

    _Quote2.owner = "Abhinav";

    cout << "_Quote2.owner = " << _Quote2.owner << endl;

    Print_Price(_Quote2);

}

void Print_Price(const Quote &_Quote) {

    double price = _Quote.net_price();
    cout << " price = " << price << endl;

}
