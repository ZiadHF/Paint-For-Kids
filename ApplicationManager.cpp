#include "ApplicationManager.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddCircAction.h"
#include"Actions/AddSqrAction.h"
#include"Actions/AddHexAction.h"
#include"Actions/AddTriAction.h"
#include "Actions/SaveAction.h"
#include"Figures/CCircle.h"
#include"Actions/LoadAction.h"
#include"Actions/SelectFigure.h"
#include"Actions/DeleteFig.h"
#include"Actions/MoveAction.h"
#include"Actions/ChangeFillColorAction.h"
#include"Actions/ChangeDrawColorAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	DelFigCount = 0;
	DelFigInd = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	//Create an array of Deleted figure pointers and sets them to NULL
	for (int i = 0; i < 5; i++)
		DelFigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;
	case DRAW_SQR:
		pAct = new AddSqrAction(this);
		break;
	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;
	case SELECT:
		pAct = new SelectFigure(this);
		break;
	case SAVE:
		pAct = new SaveAction(this);
		break;
	case LOAD:
		pAct = new LoadAction(this);
		break;
	case DEL:
		pAct = new DeleteFig(this);
		break;
	case MOVE:
		pAct = new MoveAction(this);
		break;
	case CHANGEFILL:
		pAct = new ChangeFillColorAction(this);
		break;
	case CHANGEBORDERCOLOR:
		pAct = new ChangeDrawColorAction(this);
		break;
	case EXIT:
		///create ExitAction here
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
//Returns Selected figure
CFigure* ApplicationManager::getSelectedFigure() {
	return SelectedFig;
}
//Sets Selected Figure
void ApplicationManager::setSelectedFigure(CFigure* set) {
	SelectedFig = set;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(Point in) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->Contains(in))
			return FigList[i];
	}
	return NULL;
}
//Resets FigureList and sets all Figure pointers to NULL,And also setting FigCount to 0 
void ApplicationManager::DeleteAllFigures() {
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}
//Deletes a figure and adds it to the deleted Figure list, and shifting the figure list left
void ApplicationManager::DeleteFigure(CFigure* pFig) {
	int c;
	if (FigCount > 0) {
	for(int i = 0; i<FigCount;i++)
		if (FigList[i] == pFig) {
			FigList[i] = NULL;
			c = i;
			FigCount--;
		}
	}
	for (int i = c; i < FigCount; i++) {
		FigList[i] = FigList[i + 1];
	}
}
//FigCount Getter
int ApplicationManager::getFigCount() 
{
	return FigCount;
}
//Adding deleted figures to deleted figure list
void ApplicationManager::AddDelFigure(CFigure* pFig) {
	if (DelFigInd < 5) {
		DelFigList[DelFigInd++] = pFig;
	}
	else {
		DelFigInd = 0;
		DelFigList[DelFigInd++] = pFig;
	}
	DelFigCount++;
}
// Saving each individual figure by looping on the figlist and accessing its save virtual function
void ApplicationManager::SaveAll(ofstream& OutFile) {
	OutFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(OutFile);
	}

}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Draw(pOut);
	}		//Call Draw function (virtual member fn)
	pOut->CreateDrawToolBar();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
