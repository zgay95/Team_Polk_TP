//Car CPP file. The logic inside the Car class.
#include "Car.h"

//Blank Constructor
Car::Car(){
	Make = "";
	Model = "";
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
Car::Car(string Mk, string Md, string EC, string TT, string HC, string IC, string SS, string ED, string ID, string AS, string CC, string MP, string EP)
  {
  Make = Mk;
	Model = Md;
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
  };