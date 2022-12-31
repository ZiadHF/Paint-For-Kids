#include "PickByFigure.h"
#include "..\Figures/CCircle.h"
#include "..\Figures/CRectangle.h"
#include "..\Figures/CHexagon.h"
#include "..\Figures/CTriangle.h"
#include "..\Figures/CSquare.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//Constructor
PickByFigure::PickByFigure(ApplicationManager* pApp) : Action(pApp) {
	correctcount = incorrectcount = totalcount = 0;
}


//Gets the Grade of the Kid.
string PickByFigure::GetGrade() {
	float Grade = ((float)correctcount / (correctcount+incorrectcount)) * 100;
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

//Read Parameters
void PickByFigure::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Gets a random number between 0 and FigCount-1
	int x = 0 + (rand() % (pManager->getFigCount() - 1));
	CFigure* ptr = pManager->GetFig(x);
	//Gets the count of all figures and the type of the figure.
	totalcount = pManager->GetCount(ptr,Figure);
	Type = pManager->GetType(ptr);
	//Prints the type of the figure to prompt the kid to get all those figures.
	pOut->PrintMessage("Select all " + Type + "s");
}

//Execute the action
void PickByFigure::Execute()
{
	//This action needs to read some parameters first
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	//While condition that stops when all correct figures are removed.
	while (correctcount != totalcount) {
		Point p2;
		pIn->GetPointClicked(p2.x, p2.y);
		CFigure* ptr = pManager->GetFigure(p2);
		//Checks if the (x,y) clicked is a figure.
		if (ptr != NULL)
		{
			//We get the type of figure and compare it using function compare() then we make adjustments to the counts.
			string type = pManager->GetType(ptr);
			if (!(Type.compare(type))) {
				correctcount++;
				pManager->DeleteFigure(ptr);
				pManager->UpdateInterface();
			}
			else
				incorrectcount++;
		}
	}
	//Gets the grade of the kid and prints.
	string Grade = GetGrade();
	pOut->PrintMessage("You got " + Grade + " and you got " + to_string(correctcount) + " correct clicks out of " + to_string(correctcount + incorrectcount) + " total clicks");
}

//Destructor
PickByFigure::~PickByFigure() {

}