#pragma once
#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "..\Actions/Action.h"

//Add Square Action class
class AddSqrAction : public Action
{
private:
	Point Center;//Center Corners
	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif