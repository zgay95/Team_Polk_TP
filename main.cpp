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

//This function will write the car objects that are stored in the Cars vector to the CarData file and will overwrite any previous data there
void writeCarData(vector<Car> Cars){
  ofstream CarFile; //CReate output stream and file
  CarFile.open ("CarData.csv");
  //write header to file
  CarFile << "Make,Model,Year,EngineCapacity,TransmissionType,HandlingCapability,InstrumentsAndControls,SafetyAndSecurity,ExteriorDesign,InteriorDesign,AudioSystem,ComfortAndConvenience,MaintenancePrograms,ExtraPackages";
  CarFile << endl;
  for (size_t i = 0; i < Cars.size(); i++) //for every entry in the vector write the object to the file and its own line
  {
    Car OutputCar = Cars[i];
    CarFile << OutputCar.Make << "," << OutputCar.Model << "," << OutputCar.Year << "," << OutputCar.EngineCapacity 
            << "," << OutputCar.TransmissionType << "," << OutputCar.HandlingCapability << "," << OutputCar.InstrumentsAndControls 
            << "," << OutputCar.SafetyAndSecurity << "," << OutputCar.ExteriorDesign << "," << OutputCar.InteriorDesign << "," << OutputCar.AudioSystem 
            << "," << OutputCar.ComfortAndConvenience << "," << OutputCar.MaintenancePrograms << "," << OutputCar.ExtraPackages << endl;
  }
  CarFile.close();
}

//This function will write the Customer objects that are stored in the Customers vector to the CCustomerData file and will overwrite any previous data there
void writeCustomerData(vector<Customer> Customers){
  ofstream CustomerFile; //CReate output stream and file
  CustomerFile.open ("CustomerData.csv");
  //write header to file
  CustomerFile << "FirstName,LastName,Email,Phone,Address,City,Zip,CarBought";
  CustomerFile << endl;
  for (size_t i = 0; i < Customers.size(); i++) //for every entry in the vector write the object to the file and its own line
  {
    Customer OutputCustomer = Customers[i];
    CustomerFile << OutputCustomer.FirstName << "," << OutputCustomer.LastName << "," << OutputCustomer.Email << "," << OutputCustomer.Phone 
            << "," << OutputCustomer.Address << "," << OutputCustomer.City << "," << OutputCustomer.Zip << "," << OutputCustomer.CarBought << endl;
  }
  CustomerFile.close();
}

//This function will clear the terminal for a new menu 
void clearTerminal(){
  #ifdef __linux__ 
        system("clear");
  #elif  __APPLE__ 
        system("clear");
  #elif _WIN32
        system("CLS");
  #else
  #endif

}

Car GetCarData(){
  cin.clear();
  fflush(stdin);
	Car* NewCar = new Car();
	cout << endl << "Vehicle Make:  ";
  getline(cin, NewCar->Make);
  cout << endl << "Vehicle Model: ";
  getline(cin, NewCar->Model);
  cout << endl << "Vehicle Year: ";
  getline(cin, NewCar->Year);
  cout << endl << "Vehicle Engine Capacity: ";
  getline(cin, NewCar->EngineCapacity);
  cout << endl << "Vehicle Transmission Type: ";
  getline(cin, NewCar->TransmissionType);
  cout << endl << "Vehicle Handling Capacity: ";
  getline(cin, NewCar->HandlingCapability);
  cout << endl << "Vehicle Safety and Security: ";
  getline(cin, NewCar->SafetyAndSecurity);
  cout << endl << "Vehicle Exterior Design: ";
  getline(cin, NewCar->ExteriorDesign);
  cout << endl << "Vehicle Interior Design: ";
  getline(cin, NewCar->InteriorDesign);
  cout << endl << "Vehicle Audio System: ";
  getline(cin, NewCar->AudioSystem);
  cout << endl << "Vehicle Comfort and Convenience: ";
  getline(cin, NewCar->ComfortAndConvenience);
  cout << endl << "Vehicle Maintenence Programs: ";
  getline(cin, NewCar->MaintenancePrograms);
  cout << endl << "Vehicle Extra Packages: ";
  getline(cin, NewCar->ExtraPackages);
	return *NewCar;
}

int searchInventory(Car SearchedCar){
  for (size_t i = 0; i < Cars.size(); i++)
  { 
    bool found = true;
    if (!SearchedCar.Make.empty()) //User entered a value and it matches this car data in inventory
    {
      if (SearchedCar.Make != Cars[i].Make)
      {
        found = false;
      }
    }
    if (!SearchedCar.Model.empty())
    {
      if (SearchedCar.Model != Cars[i].Model)
      {
        found = false;
      }
    }
    if (!SearchedCar.Year.empty())
    {
      if (SearchedCar.Year != Cars[i].Year)
      {
        found = false;
      }
    }
    if (!SearchedCar.EngineCapacity.empty())
    {
      if (SearchedCar.EngineCapacity != Cars[i].EngineCapacity)
      {
        found = false;
      }
    }
    if (!SearchedCar.TransmissionType.empty())
    {
      if (SearchedCar.TransmissionType != Cars[i].TransmissionType)
      {
        found = false;
      }
    }
    if (!SearchedCar.HandlingCapability.empty())
    {
      if (SearchedCar.HandlingCapability != Cars[i].HandlingCapability)
      {
        found = false;
      }
    }
    if (!SearchedCar.SafetyAndSecurity.empty())
    {
      if (SearchedCar.SafetyAndSecurity != Cars[i].SafetyAndSecurity)
      {
        found = false;
      }
    }
    if (!SearchedCar.ExteriorDesign.empty())
    {
      if (SearchedCar.ExteriorDesign != Cars[i].ExteriorDesign)
      {
        found = false;
      }
    }
    if (!SearchedCar.InteriorDesign.empty())
    {
      if (SearchedCar.InteriorDesign != Cars[i].InteriorDesign)
      {
        found = false;
      }
    }
    if (!SearchedCar.AudioSystem.empty())
    {
      if (SearchedCar.AudioSystem != Cars[i].AudioSystem)
      {
        found = false;
      }
    }
    if (!SearchedCar.ComfortAndConvenience.empty())
    {
      if (SearchedCar.ComfortAndConvenience != Cars[i].ComfortAndConvenience)
      {
        found = false;
      }
    }
    if (!SearchedCar.MaintenancePrograms.empty())
    {
      if (SearchedCar.MaintenancePrograms != Cars[i].MaintenancePrograms)
      {
        found = false;
      }
    }
    if (!SearchedCar.ExtraPackages.empty())
    {
      if (SearchedCar.ExtraPackages != Cars[i].ExtraPackages)
      {
        found = false;
      }
    }

    if (found)
    {
      int input;
      cout << endl << "Vehicle found in inventory." << endl;
      Cars[i].DisplayCarData();
      cout << endl << "Is this the vehicle you were looking for?" << endl;
      cout << "Enter 0 for Yes" << endl;
      cout << "Enter 1 for No" << endl;
      cin >> input;
      if (input == 0)
      {
        return i;
      }
    } 
  }//end loop
  cout << endl << "Vehicle not found in inventory." << endl << endl;
  return -1;
}

int checkInventory(int del){
  Car SearchedCar = GetCarData();
  int index = searchInventory(SearchedCar);
  if (del == 1 && index != -1)
  {
    Cars.erase(Cars.begin()+index);
  }
  return 1;
}

int addDeleteInventory(){
  cout << "Select a menu to add or delete a vehicle from the inventory." << endl << endl;
  cout << "Manage Inventory Menu:" << endl;
  cout << "1. Add Vehicle " << endl;
  cout << "2. Delete Vehicle " << endl;
  cout << "3. Exit " << endl << endl;

  int num, subExitCode = 0;
  cin >> num;
    switch (num)
  {
  case 1:
    {
    clearTerminal();
    //create new car object
    cout << "Please enter all details about the new vehicle." << endl << endl;
    cout << "Vehicle Addition Menu:";
    //Get inputs from suer about car details
    //add new car to vector
    Car NewCar = GetCarData();
    Cars.push_back(NewCar);
    break;
    }
  
  case 2:
    clearTerminal();
    return checkInventory(1);
    break;

  case 3:
    clearTerminal();
    return 1;

  default:
    clearTerminal();
    cout << "Please enter a valid number 1-3." << endl;
    break;
  }
}

//This function will display the main menu of the application and accept input from the user to open a submenu
int mainMenu(){
  cout << endl << "Main Menu: " << endl;
  cout << "1. Search Inventory " << endl;
  cout << "2. Add/Delete Vehicles " << endl;
  cout << "3. Process Customer Order " << endl;
  cout << "4. Manage Car Sales " << endl;
  cout << "5. Search Car History " << endl;
  cout << "6. Exit " << endl << endl;
  cout << "Please enter a number to enter that submenu. " << endl;

  int num, subExitCode = 0;
  cin >> num;
  switch (num)
  {
  case 1:
    clearTerminal();
    cout << "Enter Vehicle data to search the inventory." << endl << endl;
    cout << "Manage Inventory Menu:" << endl;
    while (subExitCode != 1)
    {
      subExitCode = checkInventory(0);
    }
    break;
  
  case 2:
    clearTerminal();
    while (subExitCode != 1)
    {
      subExitCode = addDeleteInventory();
    }
    break;
  
  case 3:
    clearTerminal();
    /* code */
    break;

  case 4:
    clearTerminal();
    /* code */
    break;

  case 5:
    clearTerminal();
    /* code */
    break;

  case 6:
    clearTerminal();
    cout << "Thanks for using the Vehicle Tracking System. Exiting Now..." << endl;
    return 6;

  default:
    clearTerminal();
    cout << "Please enter a valid number 1-6." << endl;
    break;
  }
}

int main()
{
  Cars = readInCarData(Cars);
  //cout << "Cars size: " <<  Cars.size() << endl;
  Customers = readInCustomerData(Customers);
  //cout << "Customers size: " << Customers.size() << endl;

  cout << "Welcome to the Vehicle Tracking System." << endl << endl;

  int exitCode = 0;
  while (exitCode != 6)
  {
    exitCode = mainMenu();
  }

  writeCarData(Cars);
  writeCustomerData(Customers);
  cout << "All Data Saved." << endl << endl;

  return 0;
}