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
  fcount = 0;

}

void EventAction::EndOfEventAction(const G4Event* event)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->FillNtupleDColumn(0,fEdep);
  man->FillNtupleDColumn(1,fcount);
  man->AddNtupleRow();

  fEdep = 0.;
  fcount = 0.;
  
}  
