#include "PickByFigFill.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickByFigFill::PickByFigFill(ApplicationManager* pApp) : Action(pApp) {
	correctcount = incorrectcount = totalcount = 0;
}

//Calculates the Grade of the Kid.
string PickByFigFill::GetGrade() {
	float Grade = ((float)correctcount / (correctcount + incorrectcount)) * 100;
	if (Grade >= 97)
		return "S";
	else if (Grade >= 89)
		return "A";
	else if (Grade >= 76)
		return "B";
	else if (Grade >= 67)
		return "C";
	else if (Grade >= 60)
		return "D";
	else
		return "F";
}

void PickByFigFill::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Checks if there are no filled elements in the draw area
	if (pManager->CheckNoFill()) {
		NoFill = true;
		return;
	}
	//Gets a random number between 0 and FigCount-1
	int x;
	int FigCount = pManager->getFigCount();
	CFigure* ptr;
	if (FigCount == 1)
	{
		x = 0;
		ptr = pManager->GetFig(x);
		if (ptr->IsFilled()) {
			NoFill = false;
		}
		else {
			NoFill = true;
			return;
		}
	}
	else {
		NoFill = false;
	do {
			x = 0 + (rand() % (FigCount - 1));
			ptr = pManager->GetFig(x);
	} while (!(ptr->IsFilled()));
	}
	//Gets the count of all figures and the type of the figure.
	c = ptr->GetColor();
	Type = pManager->GetType(ptr);
	totalcount = pManager->GetCount(ptr, FigFill);
	//Prints the colour to prompt the kid to get all those figures.
	pOut->PrintMessage("Select all " + ptr->CheckColor(c) + " " + Type + "s - " + to_string(totalcount - correctcount) + " remaining.");
}

//Execute the action
void PickByFigFill::Execute()
{
	//This action needs to read some parameters first
	Output * pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (NoFill) {
		pOut->PrintMessage("Pick by Figure & Fill isn't possible as there are no filled figures in the draw area.");
		return;
	}
	//While condition that stops when all correct figures are removed.
	while (correctcount != totalcount) {
		Point p2;
		pIn->GetPointClicked(p2.x, p2.y);
		CFigure* ptr = pManager->GetFigure(p2);
		//Checks if the (x,y) clicked is a figure.
		if (ptr != NULL)
		{
			//We get the type of figure and color then compare them using function compare() and ctest then we make adjustments to the counts.
			color ctest = ptr->GetColor();
			string type = pManager->GetType(ptr);
			if ((ctest == c) && !(Type.compare(type))) {
				correctcount++;
				pManager->DeleteFigure(ptr);
				//Updates the interface to show us the figure has disappeared.
				pManager->UpdateInterface();
				pOut->PrintMessage("Select all " + ptr->CheckColor(c) + " & " + Type + "s - " + to_string(totalcount - correctcount) + " remaining.");
			}
			else {
				incorrectcount++;
				pOut->PrintMessage("Select all " + ptr->CheckColor(c) + " & " + Type + "s - " + to_string(totalcount - correctcount) + " remaining.");
			}
		}
	}
	//Gets the grade of the kid and prints.
	string Grade = GetGrade();
	pOut->PrintMessage("You got " + Grade + " and you got " + to_string(correctcount) + " correct clicks out of " + to_string(correctcount + incorrectcount) + " total clicks");

}


PickByFigFill::~PickByFigFill() {

}