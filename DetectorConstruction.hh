#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "DetectorConstruction.hh"

#include "G4VUserDetectorConstruction.hh"
//#include "G4VSensitiveDetector.hh"
#include "globals.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//#include "Detsen.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
	DetectorConstruction();
	~DetectorConstruction();

	G4LogicalVolume *GetScoringVolume() const {return fScoringVolume;}

	virtual G4VPhysicalVolume *Construct();
//    virtual ConstructScintillator();

private:
	G4double fWorldSize;
	G4LogicalVolume *logicWorld;
	G4LogicalVolume *fScoringVolume;
	G4Material *NaI;
	G4Element *Na, *I;

};

#endif