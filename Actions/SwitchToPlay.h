#include "Action.h"
#include "..\ApplicationManager.h"
#pragma once

class SwitchToPlay : public Action
{
public:
	SwitchToPlay(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~SwitchToPlay();
};