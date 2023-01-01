#include "StopRecodringAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) :Action(pApp)
{}

void StopRecordingAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}
//Execute the action
void StopRecordingAction::Execute()
{
	ReadActionParameters();
	pManager->setRecFlag(false);
}