//Header file for Car class. 
#ifndef SALE_H 
#define SALE_H

#include <string>
#include "Car.h"
#include "Customer.h"

using namespace std;

class Sale{
public:
	//VARIABLES
	Car CarSold;
  Customer BuyingCustomer;
	//FUCNTIONS
	Sale();
	Sale(Car CS, Customer BC);
};

#endif /* SALE_H */