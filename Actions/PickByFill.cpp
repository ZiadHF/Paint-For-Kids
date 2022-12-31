#include "PickByFill.h"
#include "..\ApplicationManager.h"-
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickByFill::PickByFill(ApplicationManager* pApp) :Action(pApp) {
	totalcount = incorrectcount = correctcount = 0;
}

string PickByFill::GetGrade() {
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

void PickByFill::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Gets a random number between 0 and FigCount-1
	int x;
	CFigure* ptr;
	do {
		x = 0 + (rand() % (pManager->getFigCount() - 1));
		ptr = pManager->GetFig(x);

	} 
	while (!(ptr->IsFilled()));
	//Gets the count of all figures and the type of the figure.
	totalcount = pManager->GetCount(ptr,Fill);
	c = ptr->GetColor();
	//Prints the colour to prompt the kid to get all those figures.
	pOut->PrintMessage("Select all " + ptr->CheckColor(c) + " Figures");
}

//Execute the action
void PickByFill::Execute()
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
			color ctest = ptr->GetColor();
			if (ctest == c) {
				correctcount++;
				pManager->DeleteFigure(ptr);
			}
			else
				incorrectcount++;
		}
	}
	//Gets the grade of the kid and prints.
	string Grade = GetGrade();
	pOut->PrintMessage("You got " + Grade + " and you got " + to_string(correctcount) + " correct clicks out of " + to_string(correctcount + incorrectcount) + " total clicks");
}

PickByFill::~PickByFill() {

}