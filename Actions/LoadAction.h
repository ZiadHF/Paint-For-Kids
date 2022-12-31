#pragma once
#include "Action.h"
class LoadAction :public Action
{
public:
	LoadAction(ApplicationManager* pApp);
private:
	string FileName;




	void ReadActionParameters();
	color CheckColor(string x);

	void Execute();

};

