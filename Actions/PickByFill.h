#pragma once
#include "Action.h"
class PickByFill : public Action
{
	int correctcount, incorrectcount, totalcount;
	bool NoFill;
	color c;
public:
	PickByFill(ApplicationManager* pApp);
	~PickByFill();
	string GetGrade();
	void ReadActionParameters();
	void Execute();
};

