#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{

}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click on the first point");

	//Read 1st point and store in point center
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at Radius point");

	//Read 2nd point and store in point Radius
	pIn->GetPointClicked(Radius.x, Radius.y);

	CircGfxInfo.isFilled = filled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	if (!intiated) {
		ReadActionParameters();
		intiated = true;
	}
	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(Center, Radius, CircGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
}
