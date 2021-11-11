#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

#include "G4VModularPhysicsList.hh"
#include "G4VUserPhysicsList.hh"
#include "G4EmConfigurator.hh"

class G4VPhysicsConstructor;

class PhysicsList : public G4VUserPhysicsList
{
public:
	PhysicsList();
	~PhysicsList();

	void ConstructParticle();
	void ConstructProcess();

protected:
	void SetCuts();

private:
	G4VPhysicsConstructor *emPhysics;
	G4VPhysicsConstructor *decayPhysics;
	G4VPhysicsConstructor *raddecayPhysics;
};

#endif