#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	//fParticleGun = new G4ParticleGun(1);
	
	//G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	//G4ParticleDefinition *particle = particleTable->FindParticle("proton");

	//G4ThreeVector pos(0.,0.,0.);
	//G4ThreeVector mom(0.,0.,1.);

	//fParticleGun->SetParticlePosition(pos);
	//fParticleGun->SetParticleMomentumDirection(mom);
	//fParticleGun->SetParticleMomentum(100.*GeV);
	//fParticleGun->SetParticleDefinition(particle);
	
	G4int n_particle = 1;
	fParticleGun  = new G4ParticleGun(n_particle);

	fParticleGun->SetParticleEnergy(0*eV);
	fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));
	fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	//G4ParticleDefinition *particle = fParticleGun->GetParticleDefinition();
	
	//fParticleGun->GeneratePrimaryVertex(anEvent);
	
	if (fParticleGun->GetParticleDefinition() == G4Geantino::Geantino()) {  
	    G4int Z = 10, A = 24;
	    G4double ionCharge   = 0.*eplus;
	    G4double excitEnergy = 0.*keV;
	    
	    G4ParticleDefinition* ion
	       = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
	    fParticleGun->SetParticleDefinition(ion);
	    fParticleGun->SetParticleCharge(ionCharge);
  	}      
  	fParticleGun->GeneratePrimaryVertex(anEvent);
}
