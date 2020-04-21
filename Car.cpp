//Car CPP file. The logic inside the Car class.
#include "Car.h"
#include <iostream>

//Blank Constructor
Car::Car() {
	Make = "";
	Model = "";
	Year = "";
	EngineCapacity = "";
	TransmissionType = "";
	HandlingCapability = "";
	SafetyAndSecurity = "";
	ExteriorDesign = "";
	InteriorDesign = "";
	AudioSystem = "";
	ComfortAndConvenience = "";
	MaintenancePrograms = "";
	ExtraPackages = "";
};
//Populated Constructor
Car::Car(string Mk, string Md, string Y, string EC, string TT, string HC, string IC, string SS, string ED, string ID, string AS, string CC, string MP, string EP, string DD, string SM, string UR) {
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
	SchedueledMaintenance = SM;
	UnschedueledRepairs = UR;
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
	cout << endl << "Vehicle Extra Packages: " << this->ExtraPackages << endl << endl;
};

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

