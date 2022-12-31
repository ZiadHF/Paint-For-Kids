#pragma once
#include "PickAndHide.h"
#include "Actions\Action.h"
class PickByFigure : public Action
{
	int correctcount, incorrectcount, totalcount;
	string Type;
public:
	PickByFigure(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	char GetGrade();
	~PickByFigure();
};

