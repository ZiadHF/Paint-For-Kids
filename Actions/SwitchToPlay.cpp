#include "SwitchToPlay.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp): Action(pApp) {

}

void SwitchToPlay::ReadActionParameters() {

}

void SwitchToPlay::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Outputs message to let the kid know that he switched modes.
	pOut->PrintMessage("Switched to Play Mode.");
	//Creates the play toolbar and removes anything in the status bar.
	pOut->CreatePlayToolBar();
	pManager->UpdateInterface();
}

SwitchToPlay:: ~SwitchToPlay() {

}