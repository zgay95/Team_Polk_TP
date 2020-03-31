//Start on application
#include "Customer.h"
#include "Car.h"
#include "Sale.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//vectors to store data.
vector<Customer> Customers;
vector<Car> Cars;
vector<Sale> Sales;

//This functions reads in the Car data from CarData.cvs. It parses the data into the Car objects and adds to the global Car vector
vector<Car> readInCarData(vector<Car> Cars){
  ifstream CarFile; //Create file stream and open file for reading
  CarFile.open("CarData.csv");
  string line; //hold contents of the line in the files
  if (CarFile.is_open())
  {
    while (getline(CarFile, line)) //while there are still lines to read
    {
      string field; //Stores each column delim by commas
      stringstream ss (line); //stream to split
      vector<string> Fields; //vector to hold each column in its own entry
      while (getline(ss, field, ',')) //split line the was read in by commas (Assumption: all fields are always populated)
      {
        Fields.push_back(field); //add column to vector
      }
      //new object to assign values to
      Car* InputCar = new Car(Fields[0], Fields[1], Fields[2], Fields[3], Fields[4], Fields[5], Fields[6], Fields[7], Fields[8], Fields[9], Fields[10], Fields[11], Fields[12], Fields[13]); 
      Cars.push_back(*InputCar);
      Fields.clear(); //clear vector memory for next entry
    }
     CarFile.close();//close file we are done reading it
  }
  Cars.erase(Cars.begin()); //Delete first elements in the vectors as they are just the file headers
  return Cars;
}

//This functions reads in the Customer data from CustomerData.cvs. It parses the data into the Customer objects and adds to the global Customer vector
vector<Customer> readInCustomerData(vector<Customer> Customers){
  ifstream CustomerFile;
  CustomerFile.open("CustomerData.csv");
  string line;//hold contents of the line in the files
  if (CustomerFile.is_open())
  {
    while (getline(CustomerFile, line)) //while there are still lines to read
    {
      string field; //Stores each column delim by commas
      stringstream ss (line); //stream to split
      vector<string> Fields; //vector to hold each column in its own entry
      while (getline(ss, field, ',')) //split line the was read in by commas (Assumption: all fields are always populated except carbought)
      {
        Fields.push_back(field); //add column to vector
      }   
      //new object to assign values to
      Customer* InputCustomer = new Customer(Fields[0], Fields[1], Fields[2], Fields[3], Fields[4], Fields[5], Fields[6], Fields[7]);
      Customers.push_back(*InputCustomer);
      Fields.clear(); //clear vector memory for next entry
    }
    CustomerFile.close();//close file we are done reading it
  }
  Customers.erase(Customers.begin()); //Delete first elements in the vectors as they are just the file headers
  return Customers;
}

int main()
{
  Cars = readInCarData(Cars);
  cout << "Cars size: " <<  Cars.size() << endl;
  Customers = readInCustomerData(Customers);
  cout << "Customers size: " << Customers.size() << endl;


  return 0;
}