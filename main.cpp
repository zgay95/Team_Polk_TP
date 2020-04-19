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
vector<Car> readInCarData(vector<Car> Cars) {
    ifstream CarFile; //Create file stream and open file for reading
    CarFile.open("CarData.csv");
    string line; //hold contents of the line in the files
    if (CarFile.is_open())
    {
        while (getline(CarFile, line)) //while there are still lines to read
        {
            string field; //Stores each column delim by commas
            stringstream ss(line); //stream to split
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
vector<Customer> readInCustomerData(vector<Customer> Customers) {
    ifstream CustomerFile;
    CustomerFile.open("CustomerData.csv");
    string line;//hold contents of the line in the files
    if (CustomerFile.is_open())
    {
        while (getline(CustomerFile, line)) //while there are still lines to read
        {
            string field; //Stores each column delim by commas
            stringstream ss(line); //stream to split
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

vector<Sale> ReadInSaleData(vector<Sale> Sales) {
    ifstream SaleFile; //Create file stream and open file for reading
    int first = 0;
    SaleFile.open("SaleData.csv");
    string line; //hold contents of the line in the files
    if (SaleFile.is_open())
    {
        while (getline(SaleFile, line)) //while there are still lines to read
        {
            string field; //Stores each column delim by commas
            stringstream ss(line); //stream to split
            vector<string> Fields; //vector to hold each column in its own entry
            while (getline(ss, field, ',')) //split line the was read in by commas (Assumption: all fields are always populated)
            {
                Fields.push_back(field); //add column to vector
            }
            if (first != 0) {
                //new object to assign values to
                Car* InputCar = new Car(Fields[0], Fields[1], Fields[2], Fields[3], Fields[4], Fields[5], Fields[6], Fields[7], Fields[8], Fields[9], Fields[10], Fields[11], Fields[12], Fields[13]);
                Customer* InputCustomer = new Customer(Fields[14], Fields[15], Fields[16], Fields[17], Fields[18], Fields[19], Fields[20], InputCar->carName());
                Sale* InputSale = new Sale(*InputCar, *InputCustomer, Fields[21], Fields[22], Fields[23]);
                Sales.push_back(*InputSale);
            }
            first++;
            Fields.clear(); //clear vector memory for next entry
        }
        SaleFile.close();//close file we are done reading it
    }
    return Sales;
}

//This function will write the car objects that are stored in the Cars vector to the CarData file and will overwrite any previous data there
void writeCarData(vector<Car> Cars) {
    ofstream CarFile; //CReate output stream and file
    CarFile.open("CarData.csv");
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

//This function will write the Customer objects that are stored in the Customers vector to the CustomerData file and will overwrite any previous data there
void writeCustomerData(vector<Customer> Customers) {
    ofstream CustomerFile; //CReate output stream and file
    CustomerFile.open("CustomerData.csv");
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

//This function will write the Sale objects that are stored in the Sales vector to the SaleData file and will overwrite any previous data there
void writeSalesData(vector<Sale> Sales) {
    ofstream SaleFile; //Create output stream and file
    SaleFile.open("SaleData.csv");
    //write header to file
    SaleFile << "Make,Model,Year,EngineCapacity,TransmissionType,HandlingCapability,InstrumentsAndControls,SafetyAndSecurity,ExteriorDesign,InteriorDesign,AudioSystem,"
        << "ComfortAndConvenience,MaintenancePrograms,ExtraPackages,FirstName,LastName,Email,Phone,Address,City,Zip,Price,Date,Dealer" << endl;

    for (Sale sale : Sales) //for every entry in the vector write the object to the file and its own line
    {
        SaleFile << sale.printToFile() << endl;
    }
    SaleFile.close();
}

//This function will clear the terminal for a new menu 
void clearTerminal() {
#ifdef __linux__ 
    system("clear");
#elif  __APPLE__ 
    system("clear");
#elif _WIN32
    system("CLS");
#else
#endif

}

//Center Aligns data
void printSpace(string item, int lengthTotal) {
    int size = item.size();
    int leftSpace = (lengthTotal - size) / 2, rightSpace;

    if ((lengthTotal - size) % 2 == 1)
        rightSpace = leftSpace + 1;
    else
        rightSpace = leftSpace;

    cout << "|";
    for (int i = 0; i < leftSpace; i++) {
        cout << " ";
    }
    cout << item;
    for (int i = 0; i < rightSpace; i++) {
        cout << " ";
    }

}

vector<Car> filterInventory(vector<Car> carList, int filter, string desc) {
    vector<Car> filteredCars;

    if (filter == 1) {
        for (auto car : carList) {
            if (desc == car.Make)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 2) {
        for (auto car : carList) {
            if (desc == car.Model)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 3) {
        for (auto car : carList) {
            if (desc == car.Year)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 4) {
        for (auto car : carList) {
            if (desc == car.EngineCapacity)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 5) {
        for (auto car : carList) {
            if (desc == car.TransmissionType)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 6) {
        for (auto car : carList) {
            if (desc == car.HandlingCapability)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 7) {
        for (auto car : carList) {
            if (desc == car.InstrumentsAndControls)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 8) {
        for (auto car : carList) {
            if (desc == car.SafetyAndSecurity)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 9) {
        for (auto car : carList) {
            if (desc == car.ExteriorDesign)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 10) {
        for (auto car : carList) {
            if (desc == car.InteriorDesign)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 11) {
        for (auto car : carList) {
            if (desc == car.AudioSystem)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 12) {
        for (auto car : carList) {
            if (desc == car.ComfortAndConvenience)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 13) {
        for (auto car : carList) {
            if (desc == car.MaintenancePrograms)
                filteredCars.push_back(car);
        }
        return filteredCars;
    } else if (filter == 14) {
        for (auto car : carList) {
            if (desc == car.ExtraPackages)
                filteredCars.push_back(car);
        }
    }
    return filteredCars;
}

void printInventory(vector<Car> cars) {
    cout << "|";
    printSpace("Car Inventory", 53);
    cout << "||";
    cout << endl;
    for (int i = 0; i < 57; i++) {
        cout << "=";
    }
    cout << endl << "|";
    printSpace("#", 5);
    printSpace("Make", 16);
    printSpace("Model", 21);
    printSpace("Year", 8);
    cout << "||" << endl;

    int j = 1;
    for (auto car : cars) {
        cout << "|";
        printSpace(to_string(j), 5);
        printSpace(car.Make, 16);
        printSpace(car.Model, 21);
        printSpace(car.Year, 8);
        cout << "||" << endl;
        j++;
    }
    cout << endl;
}

Car findCarInInventory() {
    unsigned int choice;
    string desc;

    vector<Car> carsList = Cars;
    Car *foundCar = new Car();

    do {
        clearTerminal();
        cout << "Search For Car In Inventory" << endl << endl;
        cout << "Search By:" << endl;
        cout << "1) Make" << endl;
        cout << "2) Model" << endl;
        cout << "3) Year" << endl;
        cout << "4) Enginer Capacity" << endl;
        cout << "5) Transmission Type" << endl;
        cout << "6) Handling Capability" << endl;
        cout << "7) Instruments and Controls" << endl;
        cout << "8) Safety and Security" << endl;
        cout << "9) Exterior Design" << endl;
        cout << "10) Interior Design" << endl;
        cout << "11) Audio System" << endl;
        cout << "12) Comfort and Convenience" << endl;
        cout << "13) Maintenance Programs" << endl;
        cout << "14) Extra Packages" << endl;

        cout << "Enter the number of the filter you want to search by: ";
        cin >> choice;
        if (choice >= 1 || choice <= 14) {
            cin.ignore();
            fflush(stdin);
            cout << "Enter the desciption of the car: ";
            getline(cin, desc);
            carsList = filterInventory(carsList, choice, desc);
            if (carsList.empty()) {
                cout << "There are no cars with that desciption in the inventory" << endl;
                cout << "Would you like to restart your search? (Y/N): ";
                do {
                    cin >> desc;
                    if (desc == "Y" || desc == "y") {
                        carsList = Cars;
                        break;
                    }
                    else if (desc == "N" || desc == "n") {
                        return *foundCar;
                    }
                    else {
                        cout << "Please enter a \"Y\" to restart the search or a \"N\" to quit: ";
                    }
                } while (true);
            }
            else {
                do{
                    clearTerminal();
                    printInventory(carsList);
                    
                    cout << "1) Car has been found" << endl;
                    cout << "2) I want to see a car's details" << endl;
                    cout << "3) I want to continue searching" << endl;
                    cout << "4) I want to restart the search" << endl;
                    cout << "5) I want to quit searching" << endl << endl;
                    cout << "Please select the statement that descibes your sitiuation: " << endl;
                    cin >> choice;

                    if (choice == 1) {
                        do {
                            cout << "Enter the number of the car you want select: ";
                            cin >> choice;
                            if (choice <= carsList.size() && choice > 0) {
                                return carsList[choice-1];
                            }
                            else {
                                cout << "Invalid number. Do you want to quit? (Y/N): ";
                                do {
                                    cin >> desc;
                                    if (desc == "Y" || desc == "y") {
                                        return *foundCar;
                                    }
                                    else if (desc == "N" || desc == "n") {
                                        break;
                                    }
                                    else {
                                        cout << "Please enter a \"Y\" to continue or a \"N\" to quit: ";
                                    }
                                } while (true);
                            }
                        } while (true); 
                    }
                    else if (choice == 2) {
                        do {
                            cout << "Enter the number of the car you see the details of: ";
                            cin >> choice;
                            if (choice <= carsList.size() && choice > 0) {
                                clearTerminal();
                                carsList[choice-1].DisplayCarData();
                                do {
                                    cout << "Is this the car you were looking for? (Y/N): ";
                                    cin >> desc;
                                    if (desc == "Y" || desc == "y") {
                                        return carsList[choice - 1];
                                    }
                                    else if (desc == "N" || desc == "n") {
                                        break;
                                    }
                                    else {
                                        cout << "Invalid Input. Please enter a \"Y\" or a \"N\"";
                                    }
                                } while (true);
                                break;
                            }
                            else {
                                cout << "Invalid number. Do you want to quit? (Y/N): ";
                                do {
                                    cin >> desc;
                                    if (desc == "Y" || desc == "y") {
                                        return *foundCar;
                                    }
                                    else if (desc == "N" || desc == "n") {
                                        break;
                                    }
                                    else {
                                        cout << "Please enter a \"Y\" to continue or a \"N\" to quit: ";
                                    }
                                } while (true);
                            }
                        } while (true);
                    }
                    else if (choice == 3) {
                        break;
                    }
                    else if (choice == 4) {
                        carsList = Cars;
                        break;
                    }
                    else if (choice == 5) {
                        return *foundCar;
                    }
                    else {
                        cout << "Invalid choice. Please enter a number 1-4" << endl;
                    }
                } while (true);
            }
        }
        else {
            cout << "Option is not available/ Please enter a number between 1-14" << endl;
        }
        
    } while (true);
}

Car GetCarData() {
    cin.clear();
    fflush(stdin);
    cin.ignore();
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
    cout << endl << "Vehicle Instruments and Controls";
    getline(cin, NewCar->InstrumentsAndControls);
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

int searchInventory(Car SearchedCar) {
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
            return i;
            /*int input;
            cout << endl << "Vehicle found in inventory." << endl;
            Cars[i].DisplayCarData();
            cout << endl << "Is this the vehicle you were looking for?" << endl;
            cout << "Enter 0 for Yes" << endl;
            cout << "Enter 1 for No" << endl;
            cin >> input;
            if (input == 0)
            {
                return i;
            }*/
        }
    }//end loop
    cout << endl << "Vehicle not found in inventory." << endl << endl;
    return -1;
}

//Displays Car and Customer information of a chosen Sale
int viewSale() {
    unsigned int num;
    string choice;
    Sale sale;
    do {
        cout << "Enter which sale you want to see: ";
        cin >> num;
        if (num > 1 && num <= Sales.size()) {
            sale = Sales[num - 1];
            break;
        }
        else {
            cout << "Invalid sales number" << endl;
        }
    } while (true);
    
    do {
        clearTerminal();
        cout << "Enter what information you want to see (Car, Customer, or Both) (0 for exit): ";
        cin >> choice;
        if (choice == "Car" || choice == "car") {
            sale.CarSold.DisplayCarData();
            do {
                cout << "Would you like to continue with this sale (Y/N): ";
                cin >> choice;
                if (choice == "Y" || choice == "y") {
                    break;
                }
                else if (choice == "N" || choice == "n") {
                    return 1;
                }
                else {
                    cout << "Please enter a valid input" << endl;
                }
            } while (true);
        }
        else if (choice == "Customer" || choice == "customer") {
            sale.BuyingCustomer.DisplayCustomerData();
            do {
                cout << "Would you like to continue with this sale (Y/N): ";
                cin >> choice;
                if (choice == "Y" || choice == "y") {
                    break;
                }
                else if (choice == "N" || choice == "n") {
                    return 1;
                }
                else {
                    cout << "Please enter a valid input" << endl;
                }
            } while (true);
        }
        else if (choice == "Both" || choice == "both") {
            sale.CarSold.DisplayCarData();
            sale.BuyingCustomer.DisplayCustomerData();
            do {
                cout << "Would you like to continue with this sale (Y/N): ";
                cin >> choice;
                if (choice == "Y" || choice == "y") {
                    break;
                }
                else if (choice == "N" || choice == "n") {
                    return 1;
                }
                else {
                    cout << "Please enter a valid input" << endl;
                }
            } while (true);
        }
        else if (choice == "0") {
            return 1;
        }
        else {
            cout << "Please enter \"Car\", \"Customer\", \"Both\" or \"0\"" << endl;
        }
    } while (true);
}

//Prints the sales history
void printSales() {
    cout << "|";
    printSpace("Sales History", 108);
    cout << "||";
    cout << endl;
    for (int i = 0; i < 112; i++) {
        cout << "=";
    }
    cout << endl << "|";
    printSpace("#", 5);
    printSpace("Car Sold", 30);
    printSpace("Customer", 20);
    printSpace("Price Sold in $", 16);
    printSpace("Date Sold", 12);
    printSpace("Dealer", 20);
    cout << "||" << endl;

    int j = 1;
    for (auto sale : Sales) {
        cout << "|";
        printSpace(to_string(j), 5);
        sale.showSaleInfo();
        j++;
    }
    cout << endl;
}

//Creates a new Sale object
Sale createSale(Car* carSold, Customer* customer) {
    string price, dealer, date;
    cout << "Enter the sales information" << endl << endl;
    cout << "Date of sale (01/12/2000): ";
    cin >> date;
    cout << "Price Sold (no $): ";
    cin >> price;
    cout << "Dealer who sold car: ";
    cin >> dealer;

    Sale* sale = new Sale(*carSold, *customer, price, date, dealer);
    return *sale;
}

//Creates a new Customer object
Customer createCustomer(Car* carSold) {
    Customer* newCustomer = new Customer();

    cout << "Enter the customer's information" << endl << endl;
    cout << "First Name: ";
    cin >> newCustomer->FirstName;
    cout << "Last Name: ";
    cin >> newCustomer->LastName;
    cout << "Address: ";
    cin >> newCustomer->Address;
    cout << "City: ";
    cin >> newCustomer->City;
    cout << "Zip Code: ";
    cin >> newCustomer->Zip;
    cout << "Phone Number: ";
    cin >> newCustomer->Phone;
    std::cout << "Email: ";
    cin >> newCustomer->Email;

    return *newCustomer;
}

//Adds a sale to the Sales vector
int addSale() {
    string found;
    int option = 1;
    Car SearchedCar;
    
    do {
        clearTerminal();
        do {
            SearchedCar = findCarInInventory();
            if (SearchedCar.Make == "") {
                cout << "No car was selected" << endl;
                cout << "Would you like to search again: (Y/N): ";
                do {
                    cin >> found;
                    if (found == "Y" || found == "y") {
                        break;
                    }
                    else if (found == "N" || found == "n") {
                        return 1;
                    }
                    else {
                        cout << "Please enter a \"Y\" to search again or a \"N\" to quit: ";
                    }
                } while (true);
            }
            else {
                break;
            }
        } while (true);
        int index = searchInventory(SearchedCar);

        if (index != 1) {
            cout << "Is this the car that was sold? (Y/N): ";
            cin >> found;
            clearTerminal();

            do {
                if (found == "Y" || found == "y") {
                    Customer buyingCustomer = createCustomer(&SearchedCar);
                    Sale saleData = createSale(&SearchedCar, &buyingCustomer);
                    Sales.push_back(saleData);
                    Cars.erase(Cars.begin() + index);
                    cout << "Sale has been recorded" << endl;
                    return 1;
                }
                else if (found == "N" || found == "n") {
                    cout << "Would you like to search for the car again(0) or quit(1): ";
                    do {
                        cin >> option;
                        if (option == 1) {
                            return 1;
                        }
                        else if (option == 0) {
                            break;
                        }
                        else {
                            cout << "Please enter a \"0\" to search again or a \"1\" to quit: ";
                        }
                    } while (true);
                }
                else {
                    cout << "Please enter a 'Y' or 'N' to verify the car sold: ";
                    cin >> found;
                }
            } while (option != 0);

        }
        else {
            cout << "Would you like to search for the car again(0) or quit(1): ";
            do {
                cin >> option;
                if (option == 1) {
                    return 1;
                }
                else if (option == 0) {
                    break;
                }
                else {
                    cout << "Please enter a \"0\" to search again or a \"1\" to quit: ";
                }
            } while (true);
        }
    } while (true);
}
Customer editCustomer(Customer customer) {
    int num;
    string desc;
    do {
        clearTerminal();
        customer.DisplayCustomerData();
        cout << endl << endl;
        cout << "1) First Name" << endl;
        cout << "2) Last Name" << endl;
        cout << "3) Email" << endl;
        cout << "4) Phone Number" << endl;
        cout << "5) Address" << endl;
        cout << "6) City" << endl;
        cout << "7) Zip Code" << endl;
        cout << "0) Exit" << endl;

        cout << "What do you want to edit: ";
        cin >> num;
        if (num == 0) {
            return customer;
        }
        else if (num == 1) {
            cin.ignore();
            cout << "Enter the customer's first name: ";
            getline(cin, customer.FirstName);
        }
        else if (num == 2) {
            cin.ignore();
            cout << "Enter the customer's last name: ";
            getline(cin, customer.LastName);
        }
        else if (num == 5) {
            cin.ignore();
            cout << "Enter the customer's address: ";
            getline(cin, customer.Address);
        }
        else if (num == 6) {
            cin.ignore();
            cout << "Enter the customer's city: ";
            getline(cin, customer.City);
        }
        else if (num == 7) {
            cin.ignore();
            cout << "Enter the customer's zip code: ";
            getline(cin, customer.Zip);
        }
        else if (num == 4) {
            cin.ignore();
            do {
                cout << "Enter the customer's phone number (e.g. (123) 456-7890): ";
                getline(cin, desc);
                if (desc[0] != '(' || desc[4] != ')' || desc[9] != '-' || desc.size() > 15) {
                    cout << "Invalid Phone Number Format. Try Again" << endl;
                }
                else {
                    customer.Phone = desc;
                    break;
                }
            } while (true);
        }
        else if (num == 3) {
            cin.ignore();
            cout << "Enter the customer's email: ";
            getline(cin, customer.Email);
        }
        else {
            cout << "Invalid Option. Try Again" << endl;
        }
    }  while (true);
}

int editSale() {

    unsigned int num, car;
    string desc;
    Sale sale;
    do {
        clearTerminal();
        printSales();
        do {
            cout << "Enter the number of the sale you want to edit (0 to exit): ";
            cin >> car;
            if (car == 0) {
                return 1;
            }
            else if (car > 0 && car <= Sales.size()) {
                sale = Sales[car-1];
                break;
            }
            else {
                cout << "Invalid Sales Number" << endl;
            }
        } while (true);

        do {
            cout << "1) Car" << endl;
            cout << "2) Customer" << endl;
            cout << "3) Price Sold" << endl;
            cout << "4) Date Sold" << endl;
            cout << "5) Dealer" << endl;
            cout << "6) Back" << endl;

            cout << "What data would you like to edit: ";
            cin >> num;
            if (num < 0 || num > 6) {
                cout << "Invalid Option" << endl;
            }
            else if (num == 1) {
                Car newCar = findCarInInventory();
                if (newCar.Make != "") {
                    sale.CarSold = newCar;
                    Sales[car - 1] = sale;
                }
                break;
            }
            else if (num == 2) {
                sale.BuyingCustomer = editCustomer(sale.BuyingCustomer);
                Sales[car - 1] = sale;
                break;
            }
            else if (num == 3) {
                do {
                    cout << "Enter the price the car was sold for (No \"$\") (0 to exit): ";
                    cin >> desc;
                    if (desc != "0") {
                        sale.setPrice(desc);
                        Sales[car - 1] = sale;
                    }
                    break;
                } while (true);
            }
            else if (num == 4) {
                do {
                    cout << "Enter the date of the sale (01:12:2019) (0 to exit): ";
                    cin >> desc;
                    if (desc == "0") {
                        break;
                    }
                    else if (desc[2] != ':' || desc[5] != ':') {
                        cout << "Date is in the wrong format. Try again" << endl;
                    }
                    else if (stoi(desc.substr(0, 2)) > 12 || stoi(desc.substr(0, 2)) < 1){
                        cout << "Invalid Month. Try again" << endl;
                    }
                    else if (stoi(desc.substr(3, 5)) > 31 || stoi(desc.substr(3, 5)) < 1) {
                        cout << "Invalid Day. Try again" << endl;
                    }
                    else if (stoi(desc.substr(6, 8)) > 2200 || stoi(desc.substr(6, 8)) < 1900) {
                        cout << "Invalid Year. Try again" << endl;
                    }
                    else {
                        sale.setDate(desc);
                        Sales[car - 1] = sale;
                        break;
                    }
                } while (true);
            }
            else if (num == 5){
                cout << "Enter the name of the dealer who made the sale (0 to exit): ";
                cin >> desc;
                if (desc != "0") {
                    sale.dealer = desc;
                    Sales[car - 1] = sale;
                }
                break;
            }
            else {
                break;
            }
            break;
        } while (true);
    } while (true);

    
}

//Deletes a sale from the Sales vector
int deleteSale() {
    unsigned int num;

    do {
        cout << "Enter which sale you want to delete (0 to exit): ";
        cin >> num;
        if (num > 1 && num <= Sales.size()) {
            string choice;
            cout << "Are you sure you want to delete this sale? (Y/N): ";
            do {
                cin >> choice;
                if (choice == "Y" || choice == "y") {
                    Sales.erase(Sales.begin() + num - 1);
                    return 1;
                }
                else if (choice == "N" || choice == "n") {
                    break;
                }
                else {
                    cout << "Please enter a 'Y' or 'N' to delete the sale or not: ";
                }
            } while (true);
        }
        else {
            if (num == 0) {
                return 1;
            }
            cout << "Please enter a valid sales number or (0) to exit" << endl;
        }
    } while (true);
}

//Displays the menu for managing sales
int salesMenu() {
    int num;
    do {
        clearTerminal();
        printSales();
        cout << "Select a menu to add or delete a sale." << endl << endl;
        cout << "Manage Sales Menu:" << endl;
        cout << "1. View Sale Details" << endl;
        cout << "2. Add Sale" << endl;
        cout << "3. Edit Sale Data" << endl;
        cout << "4. Delete Sale " << endl;
        cout << "5. Exit " << endl << endl;

        cout << "Menu: ";
        cin >> num;

        switch (num) {
        case 1:
            viewSale();
            break;
        case 2:
            addSale();
            break;
        case 3:
            editSale();
            break;
        case 4:
            deleteSale();
            break;
        case 5:
            clearTerminal();
            return 1;
            break;
        default:
            cout << "Please enter a valid number 1-4." << endl;
            break;
        }
    } while (true);
}

int checkInventory(int del) {
    Car SearchedCar = findCarInInventory();
    int index = searchInventory(SearchedCar);
    if (del == 1 && index != -1)
    {
        Cars.erase(Cars.begin() + index);
    }
    return 1;
}

int addDeleteInventory() {
    int num, subExitCode = 0;
    do {
        cout << "Select a menu to add or delete a vehicle from the inventory." << endl << endl;
        cout << "Manage Inventory Menu:" << endl;
        cout << "1. Add Vehicle " << endl;
        cout << "2. Delete Vehicle " << endl;
        cout << "3. Exit " << endl << endl;

        cin >> num;
        switch (num)
        {
        case 1:
        {
            clearTerminal();
            //create new car object
            cout << "Please enter all details about the new vehicle." << endl << endl;
            cout << "Vehicle Addition Menu:";
            //Get inputs from user about car details
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
    } while (true);
}

//This function will display the main menu of the application and accept input from the user to open a submenu
int mainMenu() {
    int num, subExitCode = 0;
    do {
        clearTerminal();
        cout << "Welcome to the Vehicle Tracking System." << endl << endl;
        cout << endl << "Main Menu: " << endl;
        cout << "1. Search Inventory " << endl;
        cout << "2. Add/Delete Vehicles " << endl;
        cout << "3. Process Customer Order " << endl;
        cout << "4. Manage Car Sales " << endl;
        cout << "5. Search Car History " << endl;
        cout << "6. Exit " << endl << endl;
        cout << "Please enter a number to enter that submenu. " << endl;

        cin >> num;
        switch (num)
        {
        case 1:
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
            while (subExitCode != 1) {
                subExitCode = salesMenu();
            }
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
    } while (true);
}

int main()
{
    Cars = readInCarData(Cars);
    //cout << "Cars size: " <<  Cars.size() << endl;
    Customers = readInCustomerData(Customers);
    //cout << "Customers size: " << Customers.size() << endl;
    Sales = ReadInSaleData(Sales);

    int exitCode = 0;
    while (exitCode != 6)
    {
        exitCode = mainMenu();
    }

    writeCarData(Cars);
    writeCustomerData(Customers);
    writeSalesData(Sales);
    cout << "All Data Saved." << endl << endl;

    return 0;
}