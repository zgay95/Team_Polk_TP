//Header file for Car class. 
#ifndef SALE_H 
#define SALE_H

#include <string>
#include "Car.h"
#include "Customer.h"

using namespace std;

class Sale {
public:

	struct Date {
		int day, month, year;
	};
	//VARIABLES
	Car CarSold;
	Customer BuyingCustomer;
	double priceSold;
	Date dateSold;
	string dealer;

	//FUCNTIONS
	Sale();
	Sale(Car CS, Customer BC, string price, string date, string dealerName);
	string dateString();
	void showSaleInfo();
	void printSpace(string item, int lengthTotal, int db);
	void setPrice(string price);
	void setDate(string date);
	string printToFile();

};

#endif /* SALE_H */