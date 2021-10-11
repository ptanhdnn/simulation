#include "EventAction.hh"


EventAction::EventAction()
: G4UserEventAction()
{
	fEdep = 0.;
}

EventAction::~EventAction()
{}


void EventAction::BeginOfEventAction(const G4Event*)
{  
	fEdep = 0.;

}

void EventAction::EndOfEventAction(const G4Event*)
{
	G4cout << "Energy deposition: " << fEdep << G4endl;
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->FillNtupleDColumn(0,fEdep);
	man->AddNtupleRow();
}  
