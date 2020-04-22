//Car CPP file. The logic inside the Car class.
#include "Sale.h"
#include <iomanip>
#include <iostream>

//Blank Constructor
Sale::Sale() {
    CarSold = Car();
    BuyingCustomer = Customer();
    priceSold = 0.00;
    dateSold.day = 0;
    dateSold.month = 0;
    dateSold.year = 0;
    dealer = "";
};

//Populated Constructor
Sale::Sale(Car CS, Customer BC, string price, string date, string dealerName) {
    CarSold = CS;
    BuyingCustomer = BC;

    string::size_type sz;
    priceSold = stod(price, &sz);

    dateSold.month = stoi(date.substr(0, 2));
    dateSold.day = stoi(date.substr(3, 2));
    dateSold.year = stoi(date.substr(6, 4));

    dealer = dealerName;
};

void Sale::setPrice(string price) {
    string::size_type sz;
    priceSold = stod(price, &sz);
}

void Sale::setDate(string date) {
    dateSold.month = stoi(date.substr(0, 2));
    dateSold.day = stoi(date.substr(3, 2));
    dateSold.year = stoi(date.substr(6, 4));
}

string Sale::dateString() {
    string day, month;
    if (this->dateSold.month < 10) {
        month = "0" + to_string(this->dateSold.month);
    }
    else
        month = to_string(this->dateSold.month);
    if (dateSold.day < 10) {
        day = "0" + to_string(this->dateSold.day);
    }
    else
        day = to_string(this->dateSold.day);

    return month + ":" + day + ":" + to_string(this->dateSold.year);
}
void Sale::showSaleInfo() {
    printSpace(CarSold.carName(), 30, 0);
    printSpace(BuyingCustomer.CombineName(), 20, 0);
    printSpace(to_string(this->priceSold), 16, 1);
    printSpace(dateString(), 12, 0);
    printSpace(this->dealer, 20, 0);
    cout << "||" << endl;
}

void Sale::printSpace(string item, int lengthTotal, int db) {
    int size, leftSpace, rightSpace;
    if (db == 1) {
        if (this->priceSold < 10000) {
            size = 7;
        }
        else if (this->priceSold > 10000) {
            size = 8;
        }
        else {
            size = 9;
        }
    }
    else
        size = item.size();
    leftSpace = (lengthTotal - size) / 2;

    if ((lengthTotal - size) % 2 == 1) {
        rightSpace = leftSpace + 1;
    }
    else
        rightSpace = leftSpace;

    cout << "|";
    for (int i = 0; i < leftSpace; i++) {
        cout << " ";
    }
    if (db == 1) {
        cout << fixed << setprecision(2) << priceSold;
    }
    else
        cout << item;
    for (int i = 0; i < rightSpace; i++) {
        cout << " ";
    }
    
}

string Sale::printToFile() {
    return this->CarSold.printToFile() + "," + this->BuyingCustomer.printToFile() + "," +
        to_string(this->priceSold) + "," + this->dateString() + "," + this->dealer;
}