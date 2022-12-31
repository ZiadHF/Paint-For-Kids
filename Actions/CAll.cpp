#include "CAll.h"


void CAll::ReadActionParameters() {
}

CAll::CAll(ApplicationManager* pApp) : Action(pApp)
{
}

void CAll::Execute() {
	ReadActionParameters();
	pManager->DeleteAllFigures();
	pManager->setSelectedFigure(NULL);
	//pManager->ClearRecording();
	//pManager->ClearUndo();
}

CAll::~CAll()
{
}