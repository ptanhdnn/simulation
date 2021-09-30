#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

#include "g4csv.hh"


class EventAction : public G4UserEventAction
{
public:
    EventAction();
    ~EventAction();
    
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
    void AddEdep(G4double edep) { fEdep += edep; }

    
private:
    G4double fEdep;

    G4int count = 0;


};

#endif
