#pragma once
#include "Action.h"
class PickAndHide : public Action
{
public:
	PickAndHide(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~PickAndHide();
};
