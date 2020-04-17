//Header file for Customer class. 
#ifndef CUSTOMER_H 
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
public:
	//VARIABLES
	string FirstName;
	string LastName;
	string Email;
	string Phone;
	string Address;
	string City;
	string Zip;
	string CarBought;
	//FUCNTIONS
	Customer();
	Customer(string FN, string LN, string E, string P, string A, string C, string Z, string CB);
	void DisplayCustomerData();
	string CombineName();
	string printToFile();
};

#endif /* CUSTOMER_H */