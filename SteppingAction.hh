#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
//#include "G4ios.hh"
//#include "G4VPhysicalVolume.hh"
//#include "G4SystemOfUnits.hh"
#include "globals.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "RunAction.hh"

class EventAction;
// class DetectorConstruction;
class G4LogicalVolume;

class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction();
    
    virtual void UserSteppingAction(const G4Step*);
    
private:
    EventAction *fEventAction;
    G4LogicalVolume *fScoringVolume;
};

#endif
