#pragma once
#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "../Actions/Action.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	Point Center; //Hexagon Corners
	GfxInfo HexGfxInfo;
	boolean intiated = false;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();

};

#endif