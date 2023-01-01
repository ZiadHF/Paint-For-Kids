#pragma once

#pragma once
#ifndef CHANGE_DRAW_COLOR_ACTION_H
#define CHANGE_DRAW_COLOR_ACTION_H
#include"../Figures/CFigure.h"
#include "../Actions/Action.h"

class ChangeDrawColorAction : public Action
{
private:
	CFigure* checked = NULL;
	color PickedColor;
	ActionType PickedColorAction;
	bool intiated = false;
	color FinalColor;
public:
	ChangeDrawColorAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif