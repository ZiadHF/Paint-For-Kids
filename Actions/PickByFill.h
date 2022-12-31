#pragma once
#include "Action.h"
class PickByFill : public Action
{
	int correctcount, incorrectcount, totalcount;
	bool correct, isfilled;
	int x, y;
public:
	PickByFill(ApplicationManager* pApp);
	~PickByFill();
	char GetGrade();
	virtual void ReadActionParameters();
	virtual void Execute();
};

