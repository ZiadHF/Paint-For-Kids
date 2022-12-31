#include "SwitchToPlay.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp): Action(pApp) {

}

void SwitchToPlay::ReadActionParameters() {

}

void SwitchToPlay::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
	pManager->UpdateInterface();
}

SwitchToPlay:: ~SwitchToPlay() {

}