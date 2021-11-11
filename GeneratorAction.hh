#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

class G4ParticleGun;
class G4Event;


class GeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:

	GeneratorAction();
	~GeneratorAction();

	virtual void GeneratePrimaries(G4Event*);

private:
	G4ParticleGun *fParticleGun;
};

#endif