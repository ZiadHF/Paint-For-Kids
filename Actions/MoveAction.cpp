#include "../Actions/MoveAction.h"

#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include"../CMUgraphicsLib/auxil.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Moving Figure: please select new center");
	//pIn->GetPointClicked(clicked.x, clicked.y);
	checked = pManager->getSelectedFigure();
}

//Execute the action
void MoveAction::Execute()

{
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	//pIn->GetPointClicked(clicked.x, clicked.y);
	Output* pOut = pManager->GetOutput();
	if (checked != NULL) {
			Pause(1000);
		
		while (1) {
			pOut->ClearDrawArea();
			pIn->MousePos(clicked.x, clicked.y);
			checked->MoveFigure(clicked);
			pManager->UpdateInterface();
			if (!(pIn->MouseClicked()))
				break;
		}
	}
	else {
		pOut->PrintMessage("Please Select a figure first");
	}
}
