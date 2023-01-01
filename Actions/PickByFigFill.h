#pragma once
#include "Action.h"
class PickByFigFill : public Action
{
	int correctcount, incorrectcount, totalcount;
	string Type;
	color c;
	bool NoFill;
public:
	PickByFigFill(ApplicationManager* pApp);
	~PickByFigFill();
	string GetGrade();
	void ReadActionParameters();
	void Execute();
};

