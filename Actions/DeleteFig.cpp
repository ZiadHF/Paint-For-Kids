#include "DeleteFig.h"

#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

DeleteFig::DeleteFig(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteFig::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Deleted Figure");
	checked = pManager->getSelectedFigure();
}

//Execute the action
void DeleteFig::Execute()

{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if ( checked != NULL) {
		pManager->AddDelFigure(checked);
		pManager->DeleteFigure(checked);
		checked = NULL;
		pManager->setSelectedFigure(checked);
	}
	else {
		pOut->PrintMessage("Please Select a figure first");
	}
}
