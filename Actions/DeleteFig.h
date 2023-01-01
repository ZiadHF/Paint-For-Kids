#pragma once

#pragma once
#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H
#include"../Figures/CFigure.h"
#include "../Actions/Action.h"


class DeleteFig : public Action
{
private:
	CFigure* deletedfigures;
	Point clicked;
	CFigure* checked = NULL;
	boolean intiated = false;
public:
	DeleteFig(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif