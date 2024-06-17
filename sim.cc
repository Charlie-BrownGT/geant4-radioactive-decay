#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"

#include "G4Types.hh"
#include "G4RunManagerFactory.hh"
#include "G4SteppingVerbose.hh"
#include "Randomize.hh"

int main(int argc, char** argv)
{
	G4RunManager *runManager = new G4RunManager();
	runManager->SetUserInitialization(new MyDetectorConstruction());
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());
	runManager->Initialize();
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	G4UIExecutive *ui = new G4UIExecutive(argc, argv);
	
	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	UImanager->ApplyCommand("/control/execute visualization.mac");
	
	ui->SessionStart();
	
	delete ui;
	delete runManager;
	delete visManager;
}
