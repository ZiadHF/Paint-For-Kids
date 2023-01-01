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
	boolean intiated = false;
public:
	ChangeDrawColorAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif