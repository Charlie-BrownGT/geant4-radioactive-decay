#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
	
	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "physWorld", 0, false, 0);
	
	G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m);
	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");
	for(G4int i = 0; i < 100; i++)
	{
		for(G4int j = 0; j < 100; j++)
		{
			G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i + 0.5)*m/100, -0.5*m+(j + 0.5)*m/100, 0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*100, true);
		}
	}
		
	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("Sensitive Detector");
	
	logicDetector->SetSensitiveDetector(sensDet);
}
