#pragma once
#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H
#include"../Figures/CFigure.h"
#include "../Actions/Action.h"


class MoveAction : public Action
{
private:
	
	Point clicked;
	CFigure* checked = NULL;
	boolean intiated = false;
	Point FinalPoint;
public:
	MoveAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif