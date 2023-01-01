#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("New Hexagon: Click at the center");

	//Read Center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);


	HexGfxInfo.isFilled = filled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	if (!intiated) {
		ReadActionParameters();
		intiated = true;
	}
	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(Center, HexGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
