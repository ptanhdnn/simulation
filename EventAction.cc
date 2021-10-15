#include "EventAction.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"


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
	G4cout << "_____________________ Starting Event __________________\n" << G4endl;
}

void EventAction::EndOfEventAction(const G4Event* event)
{
	G4int evt = event->GetEventID();
	G4Run *run = static_cast<G4Run*>
				(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
	G4cout << "__________________ End Of Event __________________\n" << G4endl;
	G4cout << "Energy deposition: " << fEdep << G4endl;
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->FillNtupleDColumn(0,fEdep);
	man->AddNtupleRow();
}  
