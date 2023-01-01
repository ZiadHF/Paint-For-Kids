#include "CAll.h"


void CAll::ReadActionParameters() {
}

CAll::CAll(ApplicationManager* pApp) : Action(pApp)
{
}

void CAll::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	//Deletes all Figures and makes sure there are no selected figures.
	pManager->DeleteAllFigures();
	pManager->setSelectedFigure(NULL);
	//Clears Recording and Undo/Redo History
	//pManager->ClearRecording();
	//pManager->ClearUndo();
	pOut->PrintMessage("Cleared everything.");
}

CAll::~CAll()
{
}