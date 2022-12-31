#include"ChangeDrawColorAction.h"

#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeDrawColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change Figure Draw Color,please pick color");
	PickedColorAction = pIn->GetUserAction();
	while (PickedColorAction != RED_COLOR && PickedColorAction != BLUE_COLOR && PickedColorAction != GREEN_COLOR && PickedColorAction != ORANGE_COLOR && PickedColorAction != YELLOW_COLOR && PickedColorAction != BLACK_COLOR) {
		pOut->PrintMessage("No Color Selected, Please Select one.");
		PickedColorAction = pIn->GetUserAction();

	}
	checked = pManager->getSelectedFigure();

}

//Execute the action
void ChangeDrawColorAction::Execute()

{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->getSelectedFigure() != NULL) {
		ReadActionParameters();
		switch (PickedColorAction) {
		case RED_COLOR:
			PickedColor = RED;
			break;
		case BLUE_COLOR:
			PickedColor = BLUE;
			break;
		case GREEN_COLOR:
			PickedColor = GREEN;
			break;
		case  ORANGE_COLOR:
			PickedColor = ORANGE;
			break;
		case YELLOW_COLOR:
			PickedColor = YELLOW;
			break;
		case BLACK_COLOR:
			PickedColor = BLACK;
			break;
		}
		checked->ChngDrawClr(PickedColor);
		UI.DrawColor = PickedColor;
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("Please Select a figure first.");
	}
}
