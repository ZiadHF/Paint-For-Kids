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
    checked = pManager->getSelectedFigure();
    
}

//Execute the action
void MoveAction::Execute()
{

    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();
    if (!intiated) {
        intiated = true;
        Point clickedold;
        ReadActionParameters();
        if (checked != NULL) {
            bool dragging = false;
            while (1) {
                if (dragging == false) {
                    if (pIn->MouseClicked(clicked)) {
                        if (checked->Contains(clicked)) {
                            clickedold = clicked;
                            dragging = true;
                        }
                    }
                }
                else {
                    if (!(pIn->MouseClicked(clicked))) {
                        FinalPoint = clicked;
                        dragging = false;
                        break;
                    }
                    else {
                        if (clicked.x != clickedold.x || clicked.y != clickedold.y) {
                            checked->MoveFigure(clicked);
                            clickedold = clicked;
                            pOut->ClearDrawArea();
                            pManager->UpdateInterface();
                        }
                    }
                }
            }
        }
        else {
            pOut->PrintMessage("Please Select a figure first");
        }
    }
    else {
        checked = pManager->getSelectedFigure();
        if (checked != NULL) {
            checked->MoveFigure(FinalPoint);
        }
        else {
            pOut->PrintMessage("Please Select a figure first");
        }
    }
}

