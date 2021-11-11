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
	if (!fScoringVolume){
		const DetectorConstruction* detectorConstruction
		= static_cast<const DetectorConstruction*>
		(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
		fScoringVolume = detectorConstruction->GetScoringVolume();
	}

	G4Track *track = step->GetTrack();
	G4ParticleDefinition *particle = track->GetDefinition();

	G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()
	->GetVolume()->GetLogicalVolume();

	if (volume != fScoringVolume) return;

	G4double edep = step->GetTotalEnergyDeposit();
	G4cout << "energy deposition of step: " << edep << G4endl;
	if(edep <= 0) return;
	fEventAction->AddEdep(edep);
	
}