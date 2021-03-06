#include "GeneratorAction.hh"
#include "G4ChargedGeantino.hh"
#include "G4Geantino.hh"

GeneratorAction::GeneratorAction()
{
  G4int n_Particles = 1;
  fParticleGun = new G4ParticleGun(n_Particles);
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle =
                        particleTable->FindParticle("geantino");

    G4ThreeVector pos(0.,0.,-20.*cm);
    G4ThreeVector mom(0.,0.,1.);
    
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(0.*keV);
}

GeneratorAction::~GeneratorAction()
{
  delete fParticleGun;
}

void GeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    G4ParticleDefinition* particle = fParticleGun->GetParticleDefinition();
    
    if(particle == G4Geantino::Geantino())
    {
        G4int Z = 27;
        G4int A = 60;
        
        G4double charge   = 0.*eplus;
        G4double energy = 0.*keV;
        
        G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,energy);
        fParticleGun->SetParticleDefinition(ion);
        fParticleGun->SetParticleCharge(charge);
    }
    
    fParticleGun->GeneratePrimaryVertex(anEvent);

}