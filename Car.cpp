//Car CPP file. The logic inside the Car class.
#include "Car.h"
#include <iostream>

//Blank Constructor
Car::Car() {
	Make = " ";
	Model = " ";
	Year = " ";
	EngineCapacity = " ";
	TransmissionType = " ";
	HandlingCapability = " ";
	SafetyAndSecurity = " ";
	ExteriorDesign = " ";
	InteriorDesign = " ";
	AudioSystem = " ";
	ComfortAndConvenience = " ";
	MaintenancePrograms = " ";
	ExtraPackages = " ";
	DeliveryDate = " ";
	SchedueledMaintenance = " ";
	UnschedueledRepairs = " ";
	OrderStatus = " ";
	Customer = " ";

};
//Populated Constructor
Car::Car(string Mk, string Md, string Y, string EC, string TT, string HC, string IC, string SS, string ED, string ID, string AS, string CC, string MP, string EP, string DD, string SM, string UR, string OR, string CU) {
	Make = Mk;
	Model = Md;
	Year = Y;
	EngineCapacity = EC;
	TransmissionType = TT;
	HandlingCapability = HC;
	InstrumentsAndControls = IC;
	SafetyAndSecurity = SS;
	ExteriorDesign = ED;
	InteriorDesign = ID;
	AudioSystem = AS;
	ComfortAndConvenience = CC;
	MaintenancePrograms = MP;
	ExtraPackages = EP;
	DeliveryDate = DD;
	try {
		if (!DD.empty() && DD != " ") {
			dateOfDelivery.month = stoi(DD.substr(0, 2));
			dateOfDelivery.day = stoi(DD.substr(3, 2));
			dateOfDelivery.year = stoi(DD.substr(6, 4));
		}
	}
	catch (const invalid_argument& e) {

	}
	catch (const exception& e){}

	SchedueledMaintenance = SM;
	UnschedueledRepairs = UR;
	OrderStatus = OR;
	Customer = CU;
};

void Car::DisplayCarData()
{
	cout << endl << "Vehicle Make:  " << this->Make;
	cout << endl << "Vehicle Model: " << this->Model;
	cout << endl << "Vehicle Year: " << this->Year;
	cout << endl << "Vehicle Engine Capacity: " << this->EngineCapacity;
	cout << endl << "Vehicle Transmission Type: " << this->TransmissionType;
	cout << endl << "Vehicle Handling Capacity: " << this->HandlingCapability;
	cout << endl << "Vehicle Safety and Security: " << this->SafetyAndSecurity;
	cout << endl << "Vehicle Exterior Design: " << this->ExteriorDesign;
	cout << endl << "Vehicle Interior Design: " << this->InteriorDesign;
	cout << endl << "Vehicle Audio System: " << this->AudioSystem;
	cout << endl << "Vehicle Comfort and Convenience: " << this->ComfortAndConvenience;
	cout << endl << "Vehicle Maintenence Programs: " << this->MaintenancePrograms;
	cout << endl << "Vehicle Extra Packages: " << this->ExtraPackages;
	cout << endl << "Order Status: " << endl << endl;
};

void Car::setDate(string date) {
	try {
		DeliveryDate = date;
		dateOfDelivery.month = stoi(date.substr(0, 2));
		dateOfDelivery.day = stoi(date.substr(3, 2));
		dateOfDelivery.year = stoi(date.substr(6, 4));
	}
	catch (const exception& e) {

	}
}
string Car::dateString() {
	string day, month;
	try {
		if (this->dateOfDelivery.month < 10) {
			month = "0" + to_string(this->dateOfDelivery.month);
		}
		else
			month = to_string(this->dateOfDelivery.month);
		if (dateOfDelivery.day < 10) {
			day = "0" + to_string(this->dateOfDelivery.day);
		}
		else
			day = to_string(this->dateOfDelivery.day);

		return month + ":" + day + ":" + to_string(this->dateOfDelivery.year);
	}
	catch (const bad_alloc& e) {
		return "";
	}
	catch (const exception& e){
		return "";
	}
}

string Car::carName() {
	return this->Year + " " + this->Make + " " + this->Model;
}

string Car::printToFile() {
	string output;
	output = this->Make + "," + this->Model + "," + this->Year + "," + this->EngineCapacity
		+ "," + this->TransmissionType + "," + this->HandlingCapability + "," + this->InstrumentsAndControls
		+ "," + this->SafetyAndSecurity + "," + this->ExteriorDesign + "," + this->InteriorDesign + "," + this->AudioSystem
		+ "," + this->ComfortAndConvenience + "," + this->MaintenancePrograms + "," + this->ExtraPackages;
	return output;
}

