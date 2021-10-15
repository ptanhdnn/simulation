#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "PhysicsLists.hh"
#include "Actioninitialization.hh"

int main(int argc, char** argv)
{
    G4UIExecutive* ui = 0;

    #ifdef G4MULTITHREADED
        G4MTRunManager *runManager = new G4MTRunManager;
    #else
        G4RunManager* runManager = new G4RunManager;
    #endif
    
    auto detConstruction = new DetectorConstruction();
    runManager->SetUserInitialization(detConstruction);
    runManager->SetUserInitialization(new PhysicsList());
    runManager->SetUserInitialization(new ActionInitialization(detConstruction));

    if (argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    }
    
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    
    if(ui)
    {
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    }
    else
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }

    delete visManager;
    delete runManager;

    return 0;
}
