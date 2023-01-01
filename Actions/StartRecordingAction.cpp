#include "StartRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) :Action(pApp)
{}

void StartRecordingAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

//Execute the action
void StartRecordingAction::Execute()
{
	ReadActionParameters();
	pManager->setRecFlag(true);
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Starting Recording");
}