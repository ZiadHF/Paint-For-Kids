#pragma once
#include "Actions\Action.h"
class PickAndHide : public Action
{
public:
	bool IsPicked;
	PickAndHide(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~PickAndHide();
};
