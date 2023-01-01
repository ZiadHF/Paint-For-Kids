#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class SwitchToDraw : public Action
{
public:
	SwitchToDraw(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~SwitchToDraw();
};

