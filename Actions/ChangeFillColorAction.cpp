#include"../Actions/ChangeFillColorAction.h"

#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeFillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Change Figure Color,please pick color");
	PickedColorAction= pIn->GetUserAction();
	while (PickedColorAction != RED_COLOR&& PickedColorAction != BLUE_COLOR&& PickedColorAction != GREEN_COLOR&& PickedColorAction != ORANGE_COLOR&& PickedColorAction != YELLOW_COLOR&& PickedColorAction != BLACK_COLOR) {
		pOut->PrintMessage("No Color Selected, Please Select one.");
		PickedColorAction = pIn->GetUserAction();
	
	}
}

//Execute the action
void ChangeFillColorAction::Execute()

{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (!intiated) {
		intiated = true;
		ReadActionParameters();
		if (pManager->getSelectedFigure() != NULL) {
			checked = pManager->getSelectedFigure();
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
			checked->ChngFillClr(PickedColor);
			UI.FillColor = PickedColor;
			FinalColor = PickedColor;
			filled = true;
			pOut->ClearStatusBar();
		}
		else {
			pOut->PrintMessage("Please Select a figure first.");
		}
	}
	else {
		if (pManager->getSelectedFigure() != NULL) {
			checked=pManager->getSelectedFigure();
			checked->ChngFillClr(FinalColor);
			UI.FillColor = FinalColor;
			filled = true;
		}
		else {
			pOut->PrintMessage("Please Select a figure first.");

		}
	}
}
