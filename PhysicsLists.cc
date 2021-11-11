#include "PhysicsLists.hh"
#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList(): G4VUserPhysicsList()
{
	SetVerboseLevel(1);

	emPhysics = new G4EmStandardPhysics();
	decayPhysics = new G4DecayPhysics();
	raddecayPhysics = new G4RadioactiveDecayPhysics();
}

PhysicsList::~PhysicsList()
{
	delete emPhysics;
	delete decayPhysics;
	delete raddecayPhysics;
}

void PhysicsList::ConstructParticle()
{

	decayPhysics->ConstructParticle();
}

void PhysicsList::ConstructProcess()
{
	AddTransportation();

	decayPhysics->ConstructProcess();

	raddecayPhysics->ConstructProcess();

	emPhysics->ConstructProcess();
}

void PhysicsList::SetCuts()
{
	SetCutsWithDefault();

	if (verboseLevel>0) DumpCutValuesTable();
}