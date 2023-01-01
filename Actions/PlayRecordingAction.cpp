#include "PlayRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayRecordingAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

//Execute the action
void PlayRecordingAction::Execute()
{
	ReadActionParameters();

	pManager->resetFigList();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->ExceuteActions();
}