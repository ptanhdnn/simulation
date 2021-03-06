#include "RunAction.hh"

RunAction::RunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->CreateNtuple("Edep","Edep");
	man->CreateNtupleDColumn("Edep");
	man->FinishNtuple();
}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run *run)
{
	G4cout << "___ Run " << run->GetRunID() << "Start" <<G4endl;

	auto *man = G4AnalysisManager::Instance();

	G4String fileName = "Output";
	man->OpenFile(fileName);
}

void RunAction::EndOfRunAction(const G4Run *run)
{
	G4cout << "Number of events = " << run->GetNumberOfEvent() << G4endl;
	auto *man = G4AnalysisManager::Instance();

	man->Write();
	man->CloseFile();
}