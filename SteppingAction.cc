#include "SteppingAction.hh"
#include "G4Track.hh"
#include "G4Gamma.hh"
//#include "G4SteppingManager.hh"


SteppingAction::SteppingAction(EventAction *eventAction, 
								const DetectorConstruction *detConstruction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step *step)
{
/*	if(!fScoringVolume)
	{
		const DetectorConstruction *detectorConstruction =
			static_cast<const DetectorConstruction*>
			(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
		fScoringVolume = detectorConstruction->GetScoringVolume();
	}

	auto *volume = step->GetPreStepPoint()->GetTouchableHandle()
							->GetVolume()->GetLogicalVolume();

	if (volume != fScoringVolume) return;

	G4double edepStep = step->GetTotalEnergyDeposit();
	fEventAction->AddEdep(edepStep);
/*	if((volume == fScoringVolume) && (particle == G4Gamma::Gamma()))
	{
		G4double edepStep = step->GetTotalEnergyDeposit();
		fEventAction->AddEdep(edepStep);
	}*/

	auto volume = step->GetPreStepPoint()->GetTouchableHandle()
						->GetVolume();

	auto edep = step->GetTotalEnergyDeposit();
	G4cout << "Energy Step: " << edep << G4endl;
	fEventAction->AddEdep(edep);
}