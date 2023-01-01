#pragma once
#include "PickAndHide.h"
#include "Action.h"
class PickByFigure : public Action
{
	int correctcount, incorrectcount, totalcount;
	string Type;
public:
	PickByFigure(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	string GetGrade();
	~PickByFigure();
};

