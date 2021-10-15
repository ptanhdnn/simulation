#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

#include "GeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

class DetectorConstruction;

class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization(DetectorConstruction*);
    ~ActionInitialization();
    
	virtual void BuildForMaster() const;
    virtual void Build() const;

private:
	DetectorConstruction *fDetConstruction;
};

#endif