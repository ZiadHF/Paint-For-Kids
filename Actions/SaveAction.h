#pragma once
#include "Action.h"
class SaveAction : public Action
{
private:
	string file_name;
	boolean intiated = false;
public:
	SaveAction(ApplicationManager* pApp);

	
	 void ReadActionParameters();
	 string SaveAction::CheckColor(color x);
	
	 void Execute();
};

