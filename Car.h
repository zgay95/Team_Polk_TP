//Header file for Car class. 
#ifndef CAR_H 
#define CAR_H

#include <string>

using namespace std;

class Car{
public:
	//VARIABLES
	string Make;
	string Model;
	string Year;
	string EngineCapacity;
	string TransmissionType;
	string HandlingCapability;
	string InstrumentsAndControls;
	string SafetyAndSecurity;
	string ExteriorDesign;
  string InteriorDesign;
	string AudioSystem;
	string ComfortAndConvenience;
	string MaintenancePrograms;
	string ExtraPackages;
	//FUCNTIONS
	Car();
	Car(string Mk, string Md, string Y, string EC, string TT, string HC, string IC, string SS, string ED, string ID, string AS, string CC, string MP, string EP);
};

#endif /* CAR_H */