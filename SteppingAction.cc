#include "SteppingAction.hh"
//#include "G4Track.hh"
//#include "G4Gamma.hh"
//#include "G4SteppingManager.hh"



SteppingAction::SteppingAction(EventAction *eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step *step)
{
	if(!fScoringVolume)
	{
		const DetectorConstruction *detectorConstruction =
			static_cast<const DetectorConstruction*>
			(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
		fScoringVolume = detectorConstruction->GetScoringVolume();
	}

	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()
							->GetVolume()->GetLogicalVolume();

	if (volume != fScoringVolume) return;

	G4double edepStep = step->GetTotalEnergyDeposit();
	fEventAction->AddEdep(edepStep);
}