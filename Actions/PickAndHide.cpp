#include "PickAndHide.h"
#include "..\ApplicationManager.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) : Action(pApp) {
}

void PickAndHide::ReadActionParameters() {

}

void PickAndHide::Execute() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	pOut->PrintMessage("Please select one of the three modes.");
	Sleep(1000);
	pOut->PrintMessage("1- Pick by Figure        2- Pick by Color        3- Pick By Figure & Color.");
}

PickAndHide::~PickAndHide() {

}
