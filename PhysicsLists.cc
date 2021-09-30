#include "PhysicsLists.hh"

PhysicsList::PhysicsList()
{
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());    
}

PhysicsList::~PhysicsList()
{}
