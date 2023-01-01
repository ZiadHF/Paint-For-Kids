#include "ApplicationManager.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddCircAction.h"
#include"Actions/AddSqrAction.h"
#include"Actions/AddHexAction.h"
#include"Actions/AddTriAction.h"
#include "Actions/SaveAction.h"
#include"Figures/CCircle.h"
#include"Actions/UndoAction.h"
#include "Figures/CRectangle.h"
#include "Figures/CHexagon.h"
#include "Figures/CTriangle.h"
#include "Figures/CSquare.h"
#include"Actions/LoadAction.h"
#include"Actions/SelectFigure.h"
#include"Actions/DeleteFig.h"
#include"Actions/MoveAction.h"
#include"Actions/ChangeFillColorAction.h"
#include"Actions/ChangeDrawColorAction.h"
#include "Actions\CAll.h"
#include "Actions\PickAndHide.h"
#include "Actions\PickByFigure.h"
#include "Actions\PickByFill.h"
#include "Actions\PickByFigFill.h"
#include "Actions\SwitchToDraw.h"
#include "Actions\SwitchToPlay.h"
#include "Actions/StartRecordingAction.h"
#include "Actions/StopRecodringAction.h"
#include "Actions/PlayRecordingAction.h"
#include"Actions/RedoAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	TIndex = 0;
	FigCount = 0;
	DelFigCount = 0;
	DelFigInd = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	//Create an array of Deleted figure pointers and sets them to NULL
	for (int i = 0; i < 5; i++)
		DelFigList[i] = NULL;
	AddToTimeline(TempSaveAll());
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
		forbidRec = false;
		break;
	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		forbidRec = false;
		break;
	case DRAW_SQR:
		pAct = new AddSqrAction(this);
		forbidRec = false;
		break;
	case DRAW_HEX:
		pAct = new AddHexAction(this);
		forbidRec = false;
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		forbidRec = false;
		break;
	case SELECT:
		pAct = new SelectFigure(this);
		forbidRec = false;
		break;
	case UNDO:
		pAct = new UndoAction(this);
		forbidRec = false;
		break;
	case SAVE:
		pAct = new SaveAction(this);
		forbidRec = true;
		break;
	case LOAD:
		pAct = new LoadAction(this);
		forbidRec = true;
		break;
	case REDO:
		pAct = new RedoAction(this);
		forbidRec = false;
		break;
	case DEL:
		pAct = new DeleteFig(this);
		forbidRec = false;
		break;
	case MOVE:
		pAct = new MoveAction(this);
		forbidRec = false;
		break;
	case CHANGEFILL:
		pAct = new ChangeFillColorAction(this);
		forbidRec = false;
		break;
	case CHANGEBORDERCOLOR:
		pAct = new ChangeDrawColorAction(this);
		forbidRec = false;
		break;
	case CLEARALL:
		pAct = new CAll(this);
		forbidRec = true;
		break;
	case PICKANDHIDE:
		pAct = new PickAndHide(this);
		IsPicked = true;
		break;
	case PICKFILL:
		if (IsPicked) {
			pAct = new PickByFill(this);
			IsPicked = false;
			break;
		}
		pAct = NULL;
		break;
	case PICKFIGURE:
		if (IsPicked) {
			pAct = new PickByFigure(this);
			IsPicked = false;
			break;
		}
		pAct = NULL;
		break;
	case PICKFIGFILL:
		if (IsPicked) {
			pAct = new PickByFigFill(this);
			IsPicked = false;
			break;
		}
		pAct = NULL;
		break;
	case SWITCH:
		if (FigCount == 0)
		{
			pOut->PrintMessage("You cant switch to draw mode as there are no figures in draw area.");
			pAct = NULL;
			break;
		}
		else {
			//Save Function
			pAct = new SwitchToPlay(this);
			//Outputs message to let the kid know that he switched modes.
			pOut->PrintMessage("Switched to Play Mode.");
			break;
		}
	case SWITCHDRAW:
		//Load Function (delete file)
		pAct = new SwitchToDraw(this);
		break;
	case EXIT:
		///create ExitAction here
	case STARTREC:
		if (FigCount == 0) {
			pAct = new StartRecordingAction(this);
			RecFlag = true;
			forbidRec = true;
			break;
		}
		else {
			pOut->PrintMessage("Error,Record starts only on at the begining of the program or after clear all");
			break;
		}
	case  STOPREC:
		pAct = new StopRecordingAction(this);
		forbidRec = true;

		break;
	case  PLAYREC:
		pAct = new PlayRecordingAction(this);
		forbidRec = true;

		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	
	//Execute the created action
	
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
			if (ActType != UNDO && ActType != PLAYREC && ActType != STOPREC && ActType != SWITCH && ActType != SWITCHDRAW && ActType != REDO && ActType != PICKANDHIDE && ActType != PICKFIGURE && ActType != PICKFIGFILL && ActType != PICKFILL && ActType != SAVE && ActType != LOAD && ActType != CLEARALL && ActType != STARTREC&&ActType!=SELECT) {
				AddToTimeline(TempSaveAll());
			}
		
		if (!RecFlag || forbidRec) 
		{
			
			delete pAct;	//You may need to change this line depending to your implementation
			pAct = NULL;
		}
		else 
		{
			AddAction(pAct);
		}
			
			


		
	}
}

string ApplicationManager::TempLoadRedo() {
	if (TIndex <= 4) {
		TIndex++;
		return Timeline[TIndex - 1];

	}
	else {
		return Timeline[4];
	}
}

void ApplicationManager::AddToTimeline(string x) {
	if (TIndex != 5 && Timeline[4] == "") {
		Timeline[TIndex] = x;
		TIndex++;
	}
	else if (TIndex != 5 && Timeline[4] != "") {
		Timeline[TIndex++] = x;
		for (int i = TIndex; i < 5; i++) {
			Timeline[i] = "";
		}
	}
	else if (TIndex == 5) {
		for (int i = 0; i < 5; i++) {
			if (i == 4) {
				Timeline[4] = x;
			}
			else {
				Timeline[i] = Timeline[i + 1];
			}
		}
	}
}

		
	


void ApplicationManager::AddAction(Action* pAct)
{
	if (ActionCounter < 20) {
		history[ActionCounter] = pAct;
		ActionCounter++;
		pAct = NULL;
	}
}
void ApplicationManager::ExceuteActions() {
	for (int i = 0; i < ActionCounter; i++) {
		Sleep(1000);	
		history[i]->Execute();
		UpdateInterface();
	}
}

void ApplicationManager::setRecFlag(boolean RecControl) {
	RecFlag = RecControl;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
// reset figure list
void ApplicationManager::resetFigList() {
	for (int i = 0; i < FigCount; i++) {
		FigList[i] = NULL;
	}
	FigCount = 0;
}
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
			//delete FigList[i];
			FigList[i] = NULL;
			c = i;
			FigCount--;
		}
	}
	for (int i = c; i < FigCount; i++) {
		FigList[i] = FigList[i + 1];
	}
}

bool ApplicationManager::CheckNoFill() {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsFilled())
			return false;
	}
	return true;
}
bool ApplicationManager::CheckCircle(CFigure* ptr) {
	CCircle* c;
	c = dynamic_cast <CCircle*> (ptr);
	if (c != NULL)
		return true;
	return false;
}

bool ApplicationManager::CheckRect(CFigure* ptr) {
	CRectangle* c;
	c = dynamic_cast <CRectangle*> (ptr);
	if (c != NULL)
		return true;
	return false;
}

bool ApplicationManager::CheckSquare(CFigure* ptr) {
	CSquare* c;
	c = dynamic_cast <CSquare*> (ptr);
	if (c != NULL)
		return true;
	return false;
}

bool ApplicationManager::CheckHex(CFigure* ptr) {
	CHexagon* c;
	c = dynamic_cast <CHexagon*> (ptr);
	if (c != NULL)
		return true;
	return false;
}

bool ApplicationManager::CheckTri(CFigure* ptr) {
	CTriangle* c;
	c = dynamic_cast <CTriangle*> (ptr);
	if (c != NULL)
		return true;
	return false;
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

string ApplicationManager::TempLoad() {
	if (TIndex != 1) {
		TIndex--;
		return Timeline[TIndex - 1];

	}
	else {
		return Timeline[0];
	}
}

string ApplicationManager::TempSaveAll() {
	string save = to_string(getFigCount()) + "\n";
	for (int i = 0; i < FigCount; i++) {
		save = save + FigList[i]->TempSave() + "\n";
	}
	return save;
}
CFigure* ApplicationManager::GetFig(int x) {
	return FigList[x];
}

int ApplicationManager::GetCount(CFigure* ptr,int x) {
	int totalcount = 0;
	if (x == 0) {
		for (int i = 0; i < FigCount; i++)
		{
			if (CheckCircle(ptr)) {
				if ((dynamic_cast <CCircle*> (FigList[i])) != NULL) {
					totalcount++;
					continue;
				}
			}
			if (CheckHex(ptr)) {
				if ((dynamic_cast <CHexagon*> (FigList[i])) != NULL) {
					totalcount++;
					continue;
				}
			}
			if (CheckRect(ptr)) {
				if ((dynamic_cast <CRectangle*> (FigList[i])) != NULL) {
					totalcount++;
					continue;
				}
			}
			if (CheckSquare(ptr)) {
				if ((dynamic_cast <CSquare*> (FigList[i])) != NULL) {
					totalcount++;
					continue;
				}
			}
			if (CheckTri(ptr)) {
				if ((dynamic_cast <CTriangle*> (FigList[i])) != NULL) {
					totalcount++;
					continue;
				}
			}
		}
	}
	else if (x==1) {
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->GetColor() == ptr->GetColor())
				totalcount++;
		}
	}
	else if (x==2) {
		for (int i = 0; i < FigCount; i++)
		{
			if (CheckCircle(ptr)) {
				if (((dynamic_cast <CCircle*> (FigList[i])) != NULL) && (FigList[i]->GetColor() == ptr->GetColor())) {
					totalcount++;
					continue;
				}
			}
			if (CheckHex(ptr)) {
				if (((dynamic_cast <CHexagon*> (FigList[i])) != NULL) && (FigList[i]->GetColor() == ptr->GetColor())) {
					totalcount++;
					continue;
				}
			}
			if (CheckRect(ptr)) {
				if (((dynamic_cast <CRectangle*> (FigList[i])) != NULL) && (FigList[i]->GetColor() == ptr->GetColor())) {
					totalcount++;
					continue;
				}
			}
			if (CheckSquare(ptr)) {
				if (((dynamic_cast <CSquare*> (FigList[i])) != NULL) && (FigList[i]->GetColor() == ptr->GetColor())) {
					totalcount++;
					continue;
				}
			}
			if (CheckTri(ptr)) {
				if (((dynamic_cast <CTriangle*> (FigList[i])) != NULL) && (FigList[i]->GetColor() == ptr->GetColor())) {
					totalcount++;
					continue;
				}
			}
		}
	}
	return totalcount;
}


string ApplicationManager::GetType(CFigure* ptr) {
	if (CheckCircle(ptr)) {
		return "Circle";
	}
	if (CheckHex(ptr)) {
		return "Hexagon";
	}
	if (CheckRect(ptr)) {
		return "Rectangle";
	}
	if (CheckSquare(ptr)) {
		return "Square";
	}
	if (CheckTri(ptr)) {
		return "Triangle";
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
	//pOut->CreateDrawToolBar();
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

 