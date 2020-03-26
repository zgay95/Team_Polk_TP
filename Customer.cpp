//Customer CPP file. The logic inside the Customer class.
#include "Customer.h"

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
//Function to combine the customers anme with a space inbetween
string Customer::CombineName(){
  return FirstName + " " + LastName;
}



