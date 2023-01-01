#pragma once
#include "Action.h"
class RedoAction :public Action {
private:
    string LoadString;
public:
    RedoAction(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();
};