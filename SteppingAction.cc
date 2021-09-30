#include "SteppingAction.hh"

SteppingAction::SteppingAction(EventAction *eventAction)
{
	fEventAction = eventAction;
	fSecondary = 0;
}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step *step)
{
	G4SteppingManager *steppingManager = fpSteppingManager;
	G4Track *track = step->GetTrack();

	if (track->GetTrackStatus() == fAlive) {return;}

	fSecondary = steppingManager->GetfSecondary();

	for (size_t i = 0; i < (*fSecondary).size();i++)
	{
		if((*fSecondary)[i]->GetDefinition())
			G4double edep = (*fSecondary)[i] -> GetKineticEnergy();
			fEventAction->AddEdep(edep);
	}
}