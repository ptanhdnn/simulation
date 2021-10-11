#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction()
 : G4VUserDetectorConstruction(),
   fScoringVolume(0)
{
	fWorldSize = 5.*cm;
}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	// define a material
	//
	G4NistManager* nist = G4NistManager::Instance();
	Na = nist->FindOrBuildElement("Na");
	I = nist->FindOrBuildElement("I");
	NaI = new G4Material("NaI", 3.67*g/cm3, 2);
	NaI->AddElement(Na, 1);
	NaI->AddElement(I, 1);

	G4Material* Air = nist->FindOrBuildMaterial("G4_AIR"); 
	
	// World
	//
	G4Box*  
	solidWorld = new G4Box("World",                          //its name
									 fWorldSize/2,fWorldSize/2,fWorldSize/2);//its size
									 
	G4LogicalVolume*                         
	logicWorld = new G4LogicalVolume(solidWorld,             //its solid
																	 Air,                    //its material
																	 "World");               //its name
	G4VPhysicalVolume*                                   
	physWorld = new G4PVPlacement(0,                      //no rotation
																 G4ThreeVector(),        //at (0,0,0)
																 logicWorld,             //its logical volume
																 "World",                //its name
																 0,                      //its mother  volume
																 false,                  //no boolean operation
																 0);                     //copy number
	
	// Scintilation detector

	G4Tubs* solidScintillator = new G4Tubs("solidScintillator", 0*cm, 1.*cm, 2.*cm, 0*deg, 360*deg);
		
	G4LogicalVolume* logicScintillator = new G4LogicalVolume(solidScintillator, NaI, "logicalScintillator");

	fScoringVolume = logicScintillator;
		
	G4VPhysicalVolume* physScintillator = new G4PVPlacement(0,
								G4ThreeVector(0., 0., 0.),
								logicScintillator, "physScintillator",
								logicWorld, false, 0, true);
								
	return physWorld;
}
