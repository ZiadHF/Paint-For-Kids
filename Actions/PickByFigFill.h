#pragma once
#include "Actions\Action.h"
class PickByFigFill : public Action
{
	int correctcount, incorrectcount, totalcount;
	bool correct, isfilled;
	int x, y;
public:
	PickByFigFill(ApplicationManager* pApp);
	~PickByFigFill();
	char GetGrade();
	virtual void ReadActionParameters();
	virtual void Execute();
};

