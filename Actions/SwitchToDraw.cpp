#include "SwitchToDraw.h"
SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) : Action(pApp) {

}

void SwitchToDraw::ReadActionParameters() {

}

void SwitchToDraw::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	pManager->UpdateInterface();
}

SwitchToDraw::~SwitchToDraw() {

}