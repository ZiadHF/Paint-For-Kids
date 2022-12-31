#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	bool IsPicked = false;
	int FigCount,DelFigCount, DelFigInd;//Actual number of figures and Deleted figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* DelFigList[5];
	CFigure* SelectedFig = NULL; //Pointer to the selected figure
	
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	CFigure* getSelectedFigure();
	void DeleteAllFigures();
	void setSelectedFigure(CFigure*);
	bool CheckCircle(CFigure* ptr);
	bool CheckRect(CFigure* ptr);
	bool CheckTri(CFigure* ptr);
	bool CheckHex(CFigure* ptr);
	bool CheckSquare(CFigure* ptr);
	CFigure* GetFig(int x);
	string GetType(CFigure* ptr);
	int GetCount(CFigure* ptr,int x);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);  //Adds a new figure to the FigList
	void AddDelFigure(CFigure* pFig);
	void DeleteFigure(CFigure* pFig);
	CFigure* GetFigure(Point) const; //Search for a figure given a point inside the figure
	int getFigCount();
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SaveAll(ofstream& OutFile);
};

#endif