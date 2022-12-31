#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center point");

	//Read Center point of square
	pIn->GetPointClicked(Center.x, Center.y);


	SqrGfxInfo.isFilled = filled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(Center, SqrGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(S);
}
