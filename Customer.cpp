//Customer CPP file. The logic inside the Customer class.
#include "Customer.h"
#include <iostream>

//Blank Constructor
Customer::Customer() {
	FirstName = "";
	LastName = "";
	Email = "";
	Phone = "";
	Address = "";
	City = "";
	Zip = "";
	CarBought = "";
}
//Populated Constructor
Customer::Customer(string FN, string LN, string E, string P, string A, string C, string Z, string CB) {
	FirstName = FN;
	LastName = LN;
	Email = E;
	Phone = P;
	Address = A;
	City = C;
	Zip = Z;
	CarBought = CB;
}

void Customer::DisplayCustomerData() {
	cout << endl << "First Name:  " << this->FirstName;
	cout << endl << "Last Name: " << this->LastName;
	cout << endl << "Email: " << this->Email;
	cout << endl << "Phone: " << this->Phone;
	cout << endl << "Address: " << this->Address;
	cout << endl << "City: " << this->City;
	cout << endl << "Zip: " << this->Zip;
	cout << endl << "Car Bought: " << this->CarBought << endl << endl;
}

//Function to combine the customers anme with a space inbetween
string Customer::CombineName() {
	return FirstName + " " + LastName;
}

string Customer::printToFile() {
	return this->FirstName + "," + this->LastName + "," + this->Email + "," + this->Phone + "," + this->Address +
		"," + this->City + "," + this->Zip;
}

