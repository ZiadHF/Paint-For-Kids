#include "PickByFigFill.h"
#include "Figures\CTriangle.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

PickByFigFill::PickByFigFill(ApplicationManager* pApp) : Action(pApp) {

}

char PickByFigFill::GetGrade() {
	float Grade = ((float)correct / totalcount) * 100;
	if (Grade >= 97)
		return 'S';
	else if (Grade >= 89)
		return 'A';
	else if (Grade >= 76)
		return 'B';
	else if (Grade >= 67)
		return 'C';
	else if (Grade >= 60)
		return 'D';
	else
		return 'F';
}

void PickByFigFill::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure to begin.");
	pIn->GetPointClicked(x, y);

	/*
	Get the figure w/ color, with total count of the figure w/ same color in draw area
	if clicked on a figure, check if figure is filled or not then
	check if selected figure is the same figure and same color as the initally selected.
	If same figure and same color, increase count of correct, else increase count of incorrect
	Stops when count == total count (either with for loop or while)
	then outputs grade to user with his correct count and **OPTIONAL** a motivational msg (you'll do better next time), etc..

	**NEEDS FUNCTIONS:
	1-CHECKING IF POINT CLICKED IS A FIGURE
	2-CHCEK IF FIGURE IS FILLED OR NOT
	3-CHCEK IF COLOR IS THE SAME
	3-CHECKING FIGURE IS THE SAME
	4-A WAY TO GET THE COUNT OF ALL FIGURES W/ SAME COLOR IN THE DRAW AREA
	**/

}

//Execute the action
void PickByFigFill::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	//CHexagon* H = new CHexagon(Center, HexGfxInfo);

	//Add the Hexagon to the list of figures
	//pManager->AddFigure(H);
	char Grade = GetGrade();
	//pOut->PrintMessage("You got " + to_string(Grade) + " and you got " + to_string(correctcount) + " correct clicks out of " + to_string(correctcount + incorrectcount) + " total clicks");

}


PickByFigFill::~PickByFigFill() {

}