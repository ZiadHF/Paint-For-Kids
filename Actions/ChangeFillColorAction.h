
#pragma once
#ifndef CHANGE_FILL_COLOR_ACTION_H
#define CHANGE_FILL_COLOR_ACTION_H
#include"../Figures/CFigure.h"
#include "../Actions/Action.h"

class ChangeFillColorAction : public Action
{
private:
	
	CFigure* checked = NULL;
	color PickedColor;
	ActionType PickedColorAction;
public:
	ChangeFillColorAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif