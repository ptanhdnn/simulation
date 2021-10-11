#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "globals.hh"

#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include "RunAction.hh"

#include "Randomize.hh"
#include <iomanip>

#include "g4root.hh"
//#include "g4csv.hh"

class RunAction;

class EventAction : public G4UserEventAction
{
public:
    EventAction();
    ~EventAction();
    
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
    
    void AddEdep(G4double edep) { fEdep += edep; }

    
private:
    G4double fEdep;

    RunAction *fRunAction;


};

#endif
