#include "PickByFill.h"

#include "ApplicationManager.h"-
#include "GUI\input.h"
#include "GUI\Output.h"

PickByFill::PickByFill(ApplicationManager* pApp) :Action(pApp) {
	totalcount = 0;
	incorrectcount = 0;
	correctcount = 0;
	isfilled = false;
}

char PickByFill::GetGrade() {
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

void PickByFill::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a color to begin.");

	//Read Center and store in point Center
	pIn->GetPointClicked(x, y);


	/*
	Get the color, with total count of the color
	if clicked on a figure, check if selected figure is the same color.
	If same color, increase count of correct, else increase count of incorrect
	Stops when count == total count (either with for loop or while)
	then outputs grade to user with his correct count and **OPTIONAL** a motivational msg (you'll do better next time), etc..

	**NEEDS FUNCTIONS:
	1-CHECKING IF POINT CLICKED IS A FIGURE
	2-CHECKING IF FIGURE IS FILLED
	3-CHECKING COLOR IS THE SAME
	4-A WAY TO GET THE COUNT OF ALL FIGURES IN THE DRAW AREA
	**/
	pOut->ClearStatusBar();

}

//Execute the action
void PickByFill::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	//PickByFill* Pick = new PickByFill();

	//Add the Hexagon to the list of figures
	//pManager->AddFigure(H);
}

PickByFill::~PickByFill() {

}