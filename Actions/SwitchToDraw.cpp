#include "SwitchToDraw.h"
SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) : Action(pApp) {

}

void SwitchToDraw::ReadActionParameters() {

}

void SwitchToDraw::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Creates the draw toolbar and removes anything in the status bar.
	pOut->PrintMessage("Switched to Draw Mode.");
	pOut->CreateDrawToolBar();
	pManager->UpdateInterface();
}

SwitchToDraw::~SwitchToDraw() {

}