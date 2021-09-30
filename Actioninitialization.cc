#include "Actioninitialization.hh"

ActionInitialization::ActionInitialization()
{}


ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::Build() const
{
    GeneratorAction *generator = new GeneratorAction();
    SetUserAction(generator);
    
    RunAction *runAction = new RunAction();
    SetUserAction(runAction);
    
    EventAction *eventAction = new EventAction();
    SetUserAction(eventAction);
    
    SteppingAction *steppingAction = new SteppingAction(eventAction);
    SetUserAction(steppingAction);
}