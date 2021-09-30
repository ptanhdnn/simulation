#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"

#include "G4ios.hh"
#include "G4SteppingManager.hh"
#include "G4StepPoint.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"


#include "DetectorConstruction.hh"
#include "EventAction.hh"

class EventAction;

class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction();
    
    virtual void UserSteppingAction(const G4Step*);
    
private:
    EventAction *fEventAction;
    G4double edep;
    G4TrackVector* fSecondary;
};

#endif
