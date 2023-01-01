#pragma once
#include "Action.h"
class UndoAction :public Action {
private:
	string LoadString;
public:
	UndoAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};