
#pragma once
#ifndef CHANGE_FILL_COLOR_ACTION_H
#define CHANGE_FILL_COLOR_ACTION_H
#include"../Figures/CFigure.h"
#include "../Actions/Action.h"

class ChangeFillColorAction : public Action
{
private:
	color FinalColor;
	CFigure* checked = NULL;
	color PickedColor;
	ActionType PickedColorAction;
	bool intiated = false;
public:
	ChangeFillColorAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif