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
	int FigCount,DelFigCount, DelFigInd;//Actual number of figures , Deleted figures and Deleted figure indicies
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* DelFigList[5];//List of last 5 deleted figures(Array of pointers)
	CFigure* SelectedFig = NULL; //Pointer to the selected figure
	
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	
	ActionType GetUserAction() const;//Reads the input command from the user and returns the corresponding action type
	void DeleteAllFigures();//Clears all figures from figure list
	void ExecuteAction(ActionType); //Creates an action and executes it
	// -- Figures Management Functions

	void setSelectedFigure(CFigure*);//Setter for selected figure
	CFigure* getSelectedFigure();//Getter for selected figure
	void AddFigure(CFigure* pFig);  //Adds a new figure to the FigList
	void AddDelFigure(CFigure* pFig);//Adds figure to deleted figures list
	void DeleteFigure(CFigure* pFig);//Deletes Figure from figure list
	CFigure* GetFigure(Point) const; //Search for a figure given a point inside the figure
	int getFigCount();//Getter for figure count
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SaveAll(ofstream& OutFile);//Saves all figures in a text file
};

#endif