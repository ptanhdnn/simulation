#include "EventAction.hh"

EventAction::EventAction()
 : G4UserEventAction()
{
  fEdep = 0.;
}

EventAction::~EventAction()
{}


void EventAction::BeginOfEventAction(const G4Event* event)
{  
  fEdep = 0.;
  G4int count = 0;

}

void EventAction::EndOfEventAction(const G4Event* event)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->FillNtupleDColumn(fEdep,count++);
  man->AddNtupleRow(0);
  
}  
