//Car CPP file. The logic inside the Car class.
#include "Sale.h"

//Blank Constructor
Sale::Sale(){
	CarSold = Car();
  BuyingCustomer = Customer();
};
//Populated Constructor
Sale::Sale(Car CS, Customer BC)
  {
  CarSold = CS;
  BuyingCustomer = BC;
  };