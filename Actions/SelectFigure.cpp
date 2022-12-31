#include "SelectFigure.h"

#include"Action.h"
#include"../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

SelectFigure::SelectFigure(ApplicationManager* pApp) :Action(pApp)
{}

void SelectFigure::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Selecting Figure: Click on figure");
	
	//Read mouseclick to check if figure exists
	pIn->GetPointClicked(clicked.x, clicked.y);
	





}

//Execute the action
void SelectFigure::Execute()
{
		Output* pOut = pManager->GetOutput();
		if (pManager->getFigCount() != 0) {
			//This action needs to read some parameters first
			//Makes sure  a figure is selected ignoring pressing on empty spaces
			do {
				ReadActionParameters();
				checked = pManager->GetFigure(clicked);
			} while (checked == NULL);
			pOut->ClearStatusBar();
			//Checks if there is a selected figure
			//handles deselection of figure
			if (pManager->getSelectedFigure() != NULL) {
				
				if (pManager->getSelectedFigure() == checked) {
					pManager->getSelectedFigure()->SetSelected(false);
					pManager->setSelectedFigure(NULL);
					pOut->ClearStatusBar();
					
				}
				//handles the different figure selected case
				else {
					
					pManager->getSelectedFigure()->SetSelected(false);
					pManager->setSelectedFigure(checked);
					checked->SetSelected(!(checked->IsSelected()));
					checked->PrintInfo(pOut);
					
				}
			}
			//Handles the no selected figure case
			else {
				
				pManager->setSelectedFigure(checked);
				checked->SetSelected(!(checked->IsSelected()));
				checked->PrintInfo(pOut);
				
			}

		}
		else
			pOut->PrintMessage("No figures to select");
}
