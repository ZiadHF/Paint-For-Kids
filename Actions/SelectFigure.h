
#pragma once
#ifndef SELECT_FIGURE_ACTION_H
#define SELECT_FIGURE_ACTION_H
#include"../Figures/CFigure.h"
#include "Action.h"

//Add Circle Action class
class SelectFigure : public Action
{
private:
	Point clicked;
	CFigure* checked = NULL;
	boolean intiated = false;
public:
	SelectFigure(ApplicationManager* pApp);
	

	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif