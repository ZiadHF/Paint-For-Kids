#include "../Actions/MoveAction.h"

#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Moving Figure: please select new center");
	pIn->GetPointClicked(clicked.x, clicked.y);
	checked = pManager->getSelectedFigure();
}

//Execute the action
void MoveAction::Execute()

{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (checked != NULL) {
		checked->MoveFigure(clicked);
	}
	else {
		pOut->PrintMessage("Please Select a figure first");
	}
}
