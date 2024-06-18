#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
	
	//World volume
	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "physWorld", 0, false, 0);
	
	//Detector volume 1
	G4Box *solidDetector1 = new G4Box("solidDetector1", 0.05*m, 0.05*m, 0.05*m);
	logicDetector1 = new G4LogicalVolume(solidDetector1, worldMat, "logicDetector1");
	
	//Detector volume 2
	G4Box *solidDetector2 = new G4Box("solidDetector2", 0.05*m, 0.05*m, 0.05*m);
	logicDetector2 = new G4LogicalVolume(solidDetector2, worldMat, "logicDetector2");
	
	//Detector volume 3
	G4Box *solidDetector3 = new G4Box("solidDetector3", 0.05*m, 0.05*m, 0.05*m);
	logicDetector3 = new G4LogicalVolume(solidDetector3, worldMat, "logicDetector3");
	
	for(G4int i = 0; i < 10; i++)
	{
		for(G4int j = 0; j < 10; j++)
		{
			G4VPhysicalVolume *physDetector1 = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i + 0.5)*m/10, -0.5*m+(j + 0.5)*m/10, 0.45*m), logicDetector1, "physDetector1", logicWorld, false, j+i*10, true);
			G4VPhysicalVolume *physDetector2 = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i + 0.5)*m/10, -0.5*m+(j + 0.5)*m/10, -0.45*m), logicDetector1, "physDetector2", logicWorld, false, j+i*10, true);	
		}
	}
	for(G4int a = 0; a < 8; a++)
	{
		for(G4int b = 0; b < 10; b++)
		{
			G4VPhysicalVolume *physDetector3 = new G4PVPlacement(0, G4ThreeVector(0.45*m, -0.5*m+(b + 0.5)*m/10, -0.4*m+(a + 0.5)*m/10), logicDetector2, "physDetector3", logicWorld, false, b+a*10, true);
			G4VPhysicalVolume *physDetector4 = new G4PVPlacement(0, G4ThreeVector(-0.45*m, -0.5*m+(b + 0.5)*m/10, -0.4*m+(a + 0.5)*m/10), logicDetector2, "physDetector4", logicWorld, false, b+a*10, true);
		}
	}
	for(G4int x = 0; x < 8; x++)
	{
		for(G4int y = 0; y < 8; y++)
		{
			G4VPhysicalVolume *physDetector5 = new G4PVPlacement(0, G4ThreeVector(-0.4*m+(x + 0.5)*m/10, 0.45*m, -0.4*m+(y + 0.5)*m/10), logicDetector3, "phyDetector5", logicWorld, false, y+x*10, true);
			G4VPhysicalVolume *physDetector6 = new G4PVPlacement(0, G4ThreeVector(-0.4*m+(x + 0.5)*m/10, -0.45*m, -0.4*m+(y + 0.5)*m/10), logicDetector3, "phyDetector6", logicWorld, false, y+x*10, true);
		}
	}
	
		
	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	//Detector definition
	MySensitiveDetector *sensDet1 = new MySensitiveDetector("Sensitive Detector1");
	logicDetector1->SetSensitiveDetector(sensDet1);
	
	MySensitiveDetector *sensDet2 = new MySensitiveDetector("Sensitive Detector1");
	logicDetector2->SetSensitiveDetector(sensDet2);
	
	MySensitiveDetector *sensDet3 = new MySensitiveDetector("Sensitive Detector1");
	logicDetector3->SetSensitiveDetector(sensDet3);
}
