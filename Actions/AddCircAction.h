
#pragma once
#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "..\Actions\Action.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point Center, Radius; //Circle points
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

#endif