//Start on application
#include "Customer.h"
#include "Car.h"
#include "Sale.h"
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <limits>
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
            Car* InputCar = new Car(Fields[0], Fields[1], Fields[2], Fields[3], Fields[4], Fields[5], Fields[6], Fields[7], Fields[8], Fields[9], Fields[10], Fields[11], Fields[12], Fields[13], Fields[14], Fields[15], Fields[16], Fields[17], Fields[18]);
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
                Car* InputCar = new Car(Fields[0], Fields[1], Fields[2], Fields[3], Fields[4], Fields[5], Fields[6], Fields[7], Fields[8], Fields[9], Fields[10], Fields[11], Fields[12], Fields[13], " ", " ", " ", " ", " ");
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
    CarFile << "Make,Model,Year,EngineCapacity,TransmissionType,HandlingCapability,InstrumentsAndControls,SafetyAndSecurity,ExteriorDesign,InteriorDesign,AudioSystem,ComfortAndConvenience,MaintenancePrograms,ExtraPackages,DeliveryDate,ScheduledMaintenance,UnscheduledRepairs,OrderStatus,Customer";
    CarFile << endl;
    for (size_t i = 0; i < Cars.size(); i++) //for every entry in the vector write the object to the file and its own line
    {
        Car OutputCar = Cars[i];
        CarFile << OutputCar.Make << "," << OutputCar.Model << "," << OutputCar.Year << "," << OutputCar.EngineCapacity
            << "," << OutputCar.TransmissionType << "," << OutputCar.HandlingCapability << "," << OutputCar.InstrumentsAndControls
            << "," << OutputCar.SafetyAndSecurity << "," << OutputCar.ExteriorDesign << "," << OutputCar.InteriorDesign << "," << OutputCar.AudioSystem
            << "," << OutputCar.ComfortAndConvenience << "," << OutputCar.MaintenancePrograms << "," << OutputCar.ExtraPackages
            << "," << OutputCar.DeliveryDate << "," << OutputCar.SchedueledMaintenance << "," << OutputCar.UnschedueledRepairs << "," << OutputCar.OrderStatus << "," << OutputCar.Customer << endl;
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

void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    fflush(stdin);
}

bool isValidDate(string date) {

    try {
        if ((date[2] != ':' || date[5] != ':') && (date[2] != '-' || date[5] != '-') && (date[2] != '/' || date[5] != '/')) {
            cout << "Date is in the wrong format. Try again" << endl;
            return false;
        }
        else if (stoi(date.substr(0, 2)) > 12 || stoi(date.substr(0, 2)) < 1) {
            cout << "Invalid month. Try again" << endl;
            return false;
        }
        else if (stoi(date.substr(3, 2)) > 31 || stoi(date.substr(3, 2)) < 1) {
            cout << "Invalid day. Try again" << endl;
            return false;
        }
        else if (stoi(date.substr(6, 4)) > 2200 || stoi(date.substr(6, 4)) < 1900) {
            cout << "Invalid year. Try again" << endl;
            return false;
        }
        else if (stoi(date.substr(3, 2)) == 2 && stoi(date.substr(3, 2)) == 29 && (stoi(date.substr(6, 4)) % 4) != 0) {
            cout << "Invalid date. Try again" << endl;
            return false;
        }
        else if (stoi(date.substr(3, 2)) == 2 && stoi(date.substr(3, 2)) > 29) {
            cout << "Invalid date. Try again" << endl;
            return false;
        }
        else if (stoi(date.substr(3, 2)) == 31 && stoi(date.substr(0, 2)) != 1) {
            if (stoi(date.substr(0, 2)) != 3)
                if (stoi(date.substr(0, 2)) != 5)
                    if (stoi(date.substr(0, 2)) != 7)
                        if (stoi(date.substr(0, 2)) != 8)
                            if (stoi(date.substr(0, 2)) != 10)
                                if (stoi(date.substr(0, 2)) != 12) {
                                    cout << "Invalid date. Try again" << endl;
                                    return false;
                                }
            return true;
        }
        else {
            return true;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Date is in the wrong format. Try again" << endl;
        return false;
    }
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

//Checks if strings match regardless of case
bool checkMatch(string desc1, string desc2) {
    try {
        for (unsigned int i = 0; i < desc1.size(); i++) {
            if (desc1[i] != desc2[i]) {
                if (desc1[i] >= 'A' && desc1[i] <= 'Z') {
                    if (desc1[i] + 32 != desc2[i]) {
                        return false;
                    }
                }
                else if (desc2[i] >= 'A' && desc2[i] <= 'Z') {
                    if (desc2[i] + 32 != desc1[i]) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
    catch (const out_of_range& e) {
        return false;
    }

}

vector<Customer> filterCustomers(vector<Customer> customerList, int filter, string desc) {
    vector<Customer> filteredCustomers;

    if (filter == 1) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.FirstName))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 2) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.LastName))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 3) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.Address))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 4) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.City))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 5) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.Zip))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 6) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.Phone))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 7) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.Email))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    else if (filter == 8) {
        for (auto car : customerList) {
            if (checkMatch(desc, car.CarBought))
                filteredCustomers.push_back(car);
        }
        return filteredCustomers;
    }
    return filteredCustomers;
}

vector<Car> filterInventory(vector<Car> carList, int filter, string desc) {
    vector<Car> filteredCars;

    if (filter == 1) {
        for (auto car : carList) {
            if (checkMatch(desc, car.Make))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 2) {
        for (auto car : carList) {
            if (checkMatch(desc, car.Model))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 3) {
        for (auto car : carList) {
            if (checkMatch(desc, car.Year))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 4) {
        for (auto car : carList) {
            if (checkMatch(desc, car.EngineCapacity))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 5) {
        for (auto car : carList) {
            if (checkMatch(desc, car.TransmissionType))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 6) {
        for (auto car : carList) {
            if (checkMatch(desc, car.HandlingCapability))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 7) {
        for (auto car : carList) {
            if (checkMatch(desc, car.InstrumentsAndControls))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 8) {
        for (auto car : carList) {
            if (checkMatch(desc, car.SafetyAndSecurity))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 9) {
        for (auto car : carList) {
            if (checkMatch(desc, car.ExteriorDesign))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 10) {
        for (auto car : carList) {
            if (checkMatch(desc, car.InteriorDesign))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 11) {
        for (auto car : carList) {
            if (checkMatch(desc, car.AudioSystem))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 12) {
        for (auto car : carList) {
            if (checkMatch(desc, car.ComfortAndConvenience))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 13) {
        for (auto car : carList) {
            if (checkMatch(desc, car.MaintenancePrograms))
                filteredCars.push_back(car);
        }
        return filteredCars;
    }
    else if (filter == 14) {
        for (auto car : carList) {
            if (checkMatch(desc, car.ExtraPackages))
                filteredCars.push_back(car);
        }
    }
    else if (filter == 18) {
        for (auto car : carList) {
            if (checkMatch(desc, car.OrderStatus))
                filteredCars.push_back(car);
        }
    }
    else if (filter == 19) {
        for (auto car : carList) {
            if (checkMatch("Ordered", car.OrderStatus) || checkMatch("Backordered", car.OrderStatus) || checkMatch("Delivered", car.OrderStatus))
                filteredCars.push_back(car);
        }
    }
    return filteredCars;
}

void printCustomers(vector<Customer> customer) {
    cout << "|";
    printSpace("Customer List", 66);
    cout << "||";
    cout << endl;
    for (int i = 0; i < 70; i++) {
        cout << "=";
    }
    cout << endl << "|";
    printSpace("#", 5);
    printSpace("First Name", 14);
    printSpace("Last Name", 14);
    printSpace("Car Ordered", 30);
    cout << "||" << endl;

    int j = 1;
    for (auto c : customer) {
        cout << "|";
        printSpace(to_string(j), 5);
        printSpace(c.FirstName, 14);
        printSpace(c.LastName, 14);
        printSpace(c.CarBought, 30);
        cout << "||" << endl;
        j++;
    }
    cout << endl;
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

void printOrderStatus(vector<Car> cars) {
    cout << "|";
    printSpace("Car Inventory", 85);
    cout << "||";
    cout << endl;
    for (int i = 0; i < 89; i++) {
        cout << "=";
    }
    cout << endl << "|";
    printSpace("#", 5);
    printSpace("Make", 16);
    printSpace("Model", 21);
    printSpace("Year", 8);
    printSpace("Status", 14);
    printSpace("Date of Status", 16);
    cout << "||" << endl;

    int j = 1;
    for (auto car : cars) {
        cout << "|";
        printSpace(to_string(j), 5);
        printSpace(car.Make, 16);
        printSpace(car.Model, 21);
        printSpace(car.Year, 8);
        printSpace(car.OrderStatus, 14);
        printSpace(car.dateString(), 16);
        cout << "||" << endl;
        j++;
    }
    cout << endl;
}

Customer findCustomer() {
    int num;
    unsigned int choice;
    string desc;

    vector<Customer> customers = Customers;
    Customer* foundCustomer = new Customer();

    do {
        do {
            clearTerminal();
            cout << "Search For Customer" << endl << endl;
            cout << "Search By:" << endl;
            cout << "1) First Name" << endl;
            cout << "2) Last Name" << endl;
            cout << "3) Address" << endl;
            cout << "4) City" << endl;
            cout << "5) Zip Code" << endl;
            cout << "6) Phone Number" << endl;
            cout << "7) Email" << endl;
            cout << "8) Car Ordered" << endl;
            cout << "9) All Customers" << endl;
            cout << "0) Exit" << endl;

            do {
                cout << "Menu: ";
                cin >> num;
                clearLine();
                if (num >= 0 && num <= 9) {
                    break;
                }
                cout << "Invalid Option Please enter a number between 0-10" << endl;
            } while (true);

            if (num == 0) {
                return *foundCustomer;
            }
            else if (num == 9) {
                customers = Customers;
            }
            else {
                cout << "Enter the description: " << endl;
                cin >> desc;
                customers = filterCustomers(customers, num, desc);
                if (customers.empty()) {
                    cout << endl <<  "Customer was not found using that description";
                    do {
                        cout << "Would you like to search again (Y/N): ";
                        cin >> desc;
                        clearLine();
                        if (desc == "Y" || desc == "y") {
                            break;
                        }
                        else if (desc == "N" || desc == "n") {
                            return *foundCustomer;
                        }
                        else {
                            cout << "Invalid Input. Please enter a \"Y\" or a \"N\"";
                        }
                    } while (true);
                }
                else {
                    break;
                }

            }
        } while (true);
        do {
            clearTerminal();
            printCustomers(customers);

            cout << "1) I want to choose from the table" << endl;
            cout << "2) I want to see a customer's details" << endl;
            cout << "3) I want to continue searching" << endl;
            cout << "4) I want to restart the search" << endl;
            cout << "5) I want to quit searching" << endl << endl;

            do {
                cout << "Please select the statement that describes your situation: ";
                cin >> num;
                clearLine();
                if (num >= 0 && num <= 5) {
                    break;
                }
                cout << "Invalid Option Please enter a number between 1-5" << endl;
            } while (true);
            if (num == 1) {
                do {
                    cout << "Enter the number of the customer you want select (0 to exit): ";
                    cin >> choice;
                    clearLine();
                    if (choice >= 0 && choice <= customers.size()) {
                        break;
                    }
                    cout << "Invalid option. Try again" << endl;
                } while (true);
                if (choice == 0){
                    break;
                }
                return customers[choice - 1];
            }
            else if (num == 2) {
                do {
                    cout << "Enter the number of the customer you want to details for (0 to exit): ";
                    cin >> choice;
                    clearLine();
                    if (choice >= 0 && choice <= customers.size()) {
                        break;
                    }
                    cout << "Invalid option. Try again" << endl;
                } while (true);
                if (choice == 0) {
                    break;
                }
                clearTerminal();
                customers[choice - 1].DisplayCustomerData();
                do {
                    cout << "Is this the customer you were looking for? (Y/N): ";
                    cin >> desc;
                    if (desc == "Y" || desc == "y") {
                        return customers[choice - 1];
                    }
                    else if (desc == "N" || desc == "n") {
                        break;
                    }
                    else {
                        clearLine();
                        cout << "Invalid Input. Please enter a \"Y\" or a \"N\"";
                    }
                } while (true);
                break;
            }
            else if (num == 3) {
                break;
            }
            else if (num == 4) {
                customers = Customers;
                break;
            }
            else {
                return *foundCustomer;
            }

        } while (true);
        
    } while (true);
}

Car findCarInInventory(int mode) {
    unsigned int choice;
    string desc;

    vector<Car> carsList = Cars;
    Car* foundCar = new Car();

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
            clearLine();
            cout << "Enter the description of the car: ";
            getline(cin, desc);
            carsList = filterInventory(carsList, choice, desc);
            if (carsList.empty()) {
                cout << "There are no cars with that description in the inventory" << endl;
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
                        clearLine();
                        cout << "Please enter a \"Y\" to restart the search or a \"N\" to quit: ";
                    }
                } while (true);
            }
            else {
                do {
                    clearTerminal();
                    printInventory(carsList);

                    if (mode == 0) {
                        cout << "1) I want to see a car's details" << endl;
                        cout << "2) I want to continue searching" << endl;
                        cout << "3) I want to restart the search" << endl;
                        cout << "4) I want to quit searching" << endl << endl;
                    }
                    else {
                        cout << "1) I want to choose from the table" << endl;
                        cout << "2) I want to see a car's details" << endl;
                        cout << "3) I want to continue searching" << endl;
                        cout << "4) I want to restart the search" << endl;
                        cout << "5) I want to quit searching" << endl << endl;
                    }
                    cout << "Please select the statement that describes your situation: " << endl;
                    cin >> choice;

                    if (choice == 1 && mode != 0) {
                        do {
                            cout << "Enter the number of the car you want select: ";
                            cin >> choice;
                            if (choice <= carsList.size() && choice > 0) {
                                return carsList[choice - 1];
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
                                        clearLine();
                                        cout << "Please enter a \"Y\" to continue or a \"N\" to quit: ";
                                    }
                                } while (true);
                            }
                        } while (true);
                    }
                    else if ((choice == 2 && mode != 0) || (choice == 1 && mode == 0)) {
                        do {
                            cout << "Enter the number of the car you see the details of: ";
                            cin >> choice;
                            if (choice <= carsList.size() && choice > 0) {
                                clearTerminal();
                                carsList[choice - 1].DisplayCarData();
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
                                        clearLine();
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
                                        clearLine();
                                        cout << "Please enter a \"Y\" to continue or a \"N\" to quit: ";
                                    }
                                } while (true);
                            }
                        } while (true);
                    }
                    else if ((choice == 3 && mode != 0) || (choice == 2 && mode == 0)) {
                        break;
                    }
                    else if ((choice == 4 && mode != 0) || (choice == 3 && mode == 0)) {
                        carsList = Cars;
                        break;
                    }
                    else if ((choice == 5 && mode != 0) || (choice == 4 && mode == 0)) {
                        return *foundCar;
                    }
                    else {
                        clearLine();
                        if (mode == 0) {
                            cout << "Invalid choice. Please enter a number between 1-4" << endl;
                        }
                        else {
                            cout << "Invalid choice. Please enter a number between 1-5" << endl;
                        }
                    }
                } while (true);
            }
        }
        else {
            cout << "Option is not available. Please enter a number between 1-14" << endl;
        }

    } while (true);
}

Car GetCarData() {
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
    cout << endl << "Vehicle Instruments and Controls: ";
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

int searchCustomerList(string email) {
    for (size_t i = 0; i < Customers.size(); i++) {
        if (!Customers[i].Email.empty()) {
            if (Customers[i].Email == email)
                return i;
        }
    }
    return -1;
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
            clearLine();
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
                    clearLine();
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
                    clearLine();
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
                    clearLine();
                    cout << "Please enter a valid input" << endl;
                }
            } while (true);
        }
        else if (choice == "0") {
            return 1;
        }
        else {
            clearLine();
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
    do {
        cout << "Date of sale (01/24/2000): ";
        cin >> date;
        if (isValidDate(date)) {
            break;
        }
    } while (true);
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
    string desc;
    cout << "Enter the customer's information" << endl;
    cout << "Enter 0 at any time to quit" << endl << endl;

    cout << "First Name: ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->FirstName = desc;

    cout << "Last Name: ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->LastName = desc;

    cout << "Address: ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->Address = desc;

    cout << "City: ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->City = desc;
    cout << "Zip Code: ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->Zip = desc;

    cout << "Phone Number (e.g. (123) 456-7890): ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->Phone = desc;

    std::cout << "Email: ";
    getline(cin, desc);
    if (desc == "0") {
        newCustomer->FirstName = " ";
        return *newCustomer;
    }
    newCustomer->Email = desc;

    newCustomer->CarBought = carSold->carName();

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
            SearchedCar = findCarInInventory(1);
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
                        clearLine();
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
                            clearLine();
                            cout << "Please enter a \"0\" to search again or a \"1\" to quit: ";
                        }
                    } while (true);
                }
                else {
                    clearLine();
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
                    clearLine();
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
            cout << "Enter the customer's first name (0 to exit): ";
            getline(cin, desc);
            if (desc != "0") {
                customer.FirstName = desc;
            }
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
    } while (true);
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
                sale = Sales[car - 1];
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
                Car newCar = findCarInInventory(1);
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
                    else if (stoi(desc.substr(0, 2)) > 12 || stoi(desc.substr(0, 2)) < 1) {
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
            else if (num == 5) {
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
    Car SearchedCar = findCarInInventory(0);
    int index = searchInventory(SearchedCar);
    if (del == 1 && index != -1)
    {
        Cars.erase(Cars.begin() + index);
    }
    return 1;
}

int addDeleteInventory() {
    int num;
    do {
        cout << "Select a menu to add or delete a vehicle from the inventory." << endl << endl;
        cout << "Manage Inventory Menu:" << endl;
        cout << "1. Add Vehicle " << endl;
        cout << "2. Delete Vehicle " << endl;
        cout << "3. Exit " << endl << endl;

        cin >> num;
        clearLine();
        switch (num)
        {
        case 1:
        {
            clearTerminal();
            //create new car object
            cout << "Please enter all details about the new vehicle." << endl << endl;
            cout << "Vehicle Addition Menu: " << endl;
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

int VehicleHistory() {
    int num, key;
    do {
        clearTerminal();
        cout << "Search for a Vehicle to find its History." << endl << endl;
        cout << "Search Vehicle History Menu:" << endl;
        cout << "1. Search For Vehicle " << endl;
        cout << "2. Exit " << endl << endl;

        cin >> num;
        switch (num)
        {
        case 1:
        {
            clearTerminal();
            //Search for the vehicle then display its history
            Car SearchedCar = findCarInInventory(1);
            cout << endl << "Vehicle History " << endl;
            cout << "Delivery Date: " << SearchedCar.DeliveryDate << endl;
            cout << "Scheduled Maintenance: " << SearchedCar.SchedueledMaintenance << endl;
            cout << "Unscheduled Repairs: " << SearchedCar.UnschedueledRepairs << endl << endl;
            cout << "Press any number key to continue... " << endl;
            cin >> key;
            clearLine();
            break;
        }
        case 2:
            clearTerminal();
            return 1;

        default:
            clearTerminal();
            clearLine();
            cout << "Please enter a valid number 1-2." << endl;
            break;
        }
    } while (true);
}

int editOrder() {
    vector<Car> orderedCars;
    unsigned int order;
    int num;
    int index = 0, carIndex;
        
    do {
        clearTerminal();
        cout << "Edit Order" << endl << endl;
        orderedCars = filterInventory(Cars, 19, "All");
        printOrderStatus(orderedCars);
        
        do {
            cout << "Enter the number of the order you would like to change (0 to exit): ";
            cin >> order;
            clearLine();
            if (order >= 0 && order <= orderedCars.size()) {
                break;
            }
            cout << "Invalid Option. Try again" << endl;
        } while (true);

        if (order == 0) {
            return 1;
        }
        else {
            do {
                clearTerminal();
                orderedCars = filterInventory(Cars, 19, "All");
                printOrderStatus(orderedCars);
                cout << "1) Customer" << endl;
                cout << "2) Order Date" << endl;
                cout << "3) Order Status" << endl;
                cout << "4) Delete Order" << endl;
                cout << "0) Exit" << endl;
                
                do {
                    cout << "What would you like to edit: ";
                    cin >> num;
                    clearLine();
                    if (num >= 0 && num <= 4) {
                        break;
                    }
                    cout << "Invalid Option Please enter a number between 0-4" << endl;
                } while (true);
                if (num == 0) {
                    break;
                }
                else if (num == 1) {
                    Customer customer;
                    index = searchCustomerList(orderedCars[order-1].Customer);
                    carIndex = searchInventory(orderedCars[order-1]);
                    if (index == -1) {
                        cout << "Customer could not be found" << endl;
                    }
                    else {
                        customer = editCustomer(Customers[index]);
                        Cars[carIndex].Customer = customer.Email;
                    }
                }
                else if(num == 2) {
                    string desc;
                    index = searchInventory(orderedCars[order-1]);
                    do {
                        cout << "Enter Order Date (e.g. 01:24:2020) (0 to exit): ";
                        cin >> desc;
                        clearLine();
                        if (isValidDate(desc) || desc == "0") {
                            break;
                        }
                    } while (true);
                    if (desc != "0")
                        Cars[index].setDate(desc);
                }
                else if (num == 3){
                    string desc;
                    index = searchInventory(orderedCars[order-1]);
                    do {
                        cout << "Enter Order Status (e.g. Ordered, Backordered, or Delivered) (0 to exit): ";
                        cin >> desc;
                        clearLine();
                        if (checkMatch("Ordered", desc) || checkMatch("Backordered", desc) || checkMatch("Delivered", desc) || desc == "0") {
                            break;
                        }
                        cout << "Invalid Option. Try again" << endl;
                    } while (true);
                    if (desc != "0")
                        Cars[index].OrderStatus = desc;
                }
                else {
                    string choice;
                    index = searchInventory(orderedCars[order-1]);
                    cout << "Are you sure you want to delete this order? (Y/N): ";
                    do {
                        cin >> choice;
                        clearLine();
                        if (choice != "Y" || choice != "y" || choice != "N" || choice != "n") {
                            cout << "Please enter a 'Y' or 'N' to delete the order or not: ";
                        }
                        else
                            break;
                    } while (true);
                    if (choice == "Y" || choice == "y") {
                        Cars[index].Customer = " ";
                        Cars[index].DeliveryDate = " ";
                        Cars[index].OrderStatus = " ";
                        break;
                    }
                }

            } while (true);
        }
        
    } while (true);
}

int processOrderMenu() {
    int num;
    vector<Car> cars;
    string desc;
    do {
        cars = Cars;
        clearTerminal();
        cout << "Process Order" << endl << endl;
        cout << "1) Process Order For Existing Customer" << endl;
        cout << "2) Process Order For New Customer" << endl;
        cout << "3) Edit Order" << endl;
        cout << "0) Exit" << endl;

        do {
            cout << "Menu: ";
            cin >> num;
            clearLine();
            if (num >= 0 && num <= 3) {
                break;
            }
            cout << "Invalid Option Please enter a number between 0-3" << endl;
        } while (true);

        if (num == 0) {
            return 0;
        }
        else if (num == 1) {
            clearTerminal();
            Car carOrdered = GetCarData();
            clearTerminal();
            Customer customer = findCustomer();
            if (customer.FirstName != " ") {
                do {
                    cout << "Enter Order Date (e.g. 01:24:2020): ";
                    cin >> desc;
                    clearLine();
                    if (isValidDate(desc)) {
                        break;
                    }
                } while (true);
                carOrdered.setDate(desc);
                do {
                    cout << "Enter Order Status (e.g. Ordered, Backordered, or Delivered) (0 to exit): ";
                    cin >> desc;
                    clearLine();
                    if (checkMatch(desc, "Ordered") || checkMatch(desc, "Backordered") || checkMatch(desc, "Delivered") || desc == "0") {
                        break;
                    }
                    cout << "Invalid Option. Try again" << endl;
                } while (true);
                if (desc != "0") {
                    carOrdered.OrderStatus = desc;
                    Cars.push_back(carOrdered);
                }
            }
        }
        else if (num == 2) {
            clearTerminal();
            Car carOrdered = GetCarData();
            clearTerminal();
            Customer customer = createCustomer(&carOrdered);
            if (customer.FirstName != " ") {
                do {
                    cout << "Enter Order Date (e.g. 01:24:2020): ";
                    cin >> desc;
                    clearLine();
                    if (isValidDate(desc)) {
                        break;
                    }
                } while (true);
                carOrdered.setDate(desc);
                do {
                    cout << "Enter Order Status (e.g. Ordered, Backordered, or Delivered) (0 to exit): ";
                    cin >> desc;
                    clearLine();
                    if (checkMatch("Ordered", desc) || checkMatch("Backordered", desc) || checkMatch("Delivered", desc) || desc == "0") {
                        break;
                    }
                    cout << "Invalid Option. Try again" << endl;
                } while (true);
                if (desc != "0") {
                    carOrdered.OrderStatus = desc;
                    Cars.push_back(carOrdered);
                }
            }
        }
        else {
            editOrder();
        }

    } while (true);
}

int viewOrderStatus() {
    int num;
    string choice;
    vector<Car> cars;

    do {
        clearTerminal();
        cout << "Order Status" << endl << endl;
        cout << "1) Ordered" << endl;
        cout << "2) Backordered" << endl;
        cout << "3) Recently Delivered" << endl;
        cout << "4) All Orders" << endl;
        cout << "0) Exit" << endl;

        cars = Cars;
        do {
            cout << "What orders to view: ";
            cin >> num;
            clearLine();
            if (num >= 0 && num <= 4) {
                break;
            }
            cout << "Invalid Option Please enter a number between 0-4" << endl;
        } while (true);


        if (num == 0) {
            return 0;
        }
        else if (num == 1) {
            cars = filterInventory(cars, 18, "Ordered");
            if (cars.empty()) {
                cout << "There are no cars currently on order" << endl;
            }
            else {
                printOrderStatus(cars);
            }

        }
        else if (num == 2) {
            cars = filterInventory(cars, 18, "Backordered");
            if (cars.empty()) {
                cout << "There are no cars currently on backorder" << endl;
            }
            else {
                printOrderStatus(cars);
            }
        }
        else if (num == 3) {
            cars = filterInventory(cars, 18, "Delivered");
            if (cars.empty()) {
                cout << "No cars have been recently delivered" << endl;
            }
            else {
                printOrderStatus(cars);
            }
        }
        else {
            cars = filterInventory(cars, 19, "All");
            if (cars.empty()) {
                cout << "There are no cars being ordered, backordered, or delivered" << endl;
            }
            else {
                printOrderStatus(cars);
            }
        }

        cout << "Would you like to continue (Y/N): ";
        do {
            cin >> choice;
            if (choice == "Y" || choice == "y") {
                break;
            }
            else if (choice == "N" || choice == "n") {
                return 1;
            }
            else {
                clearLine();
                cout << "Please enter a \"Y\" to continue or a \"N\" to quit: ";
            }
        } while (true);
    } while (true);
}

int orderStatusMenu() {
    int num;

    do {
        clearTerminal();
        cout << "Order Status Menu" << endl << endl;
        cout << "1) Process Customer Order" << endl;
        cout << "2) View Car Order Status" << endl;
        cout << "0) Exit" << endl;

        do {
            cout << "Menu: ";
            cin >> num;
            clearLine();
            if (num <= 2 && num >= 0) {
                break;
            }
            cout << "Invalid Option. Please enter a number between 0-2" << endl;
        } while (true);

        if (num == 0) {
            return 1;
        }
        else if (num == 1) {
            processOrderMenu();
        }
        else if (num == 2) {
            viewOrderStatus();
        }
    } while (true);
}

//This function will display the main menu of the application and accept input from the user to open a submenu
int mainMenu() {
    int num, subExitCode = 0;
    do {
        clearTerminal();
        subExitCode = 0;
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
            while (subExitCode != 1)
            {
                subExitCode = orderStatusMenu();
            }
            break;

        case 4:
            clearTerminal();
            while (subExitCode != 1) {
                subExitCode = salesMenu();
            }
            break;

        case 5:
            clearTerminal();
            while (subExitCode != 1) {
                subExitCode = VehicleHistory();
            }
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
