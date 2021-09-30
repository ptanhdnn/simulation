#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "DetectorConstruction.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
	DetectorConstruction();
	~DetectorConstruction();

	virtual G4VPhysicalVolume *Construct();
    void ConstructScintillator();

private:
	G4double fWorldSize;
};

#endif