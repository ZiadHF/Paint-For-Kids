#pragma once
#ifndef START_RECORDING_ACTION-H
#define START_RECORDING_ACTION_H

#include "Action.h"

class StartRecordingAction : public Action
{
private:
public:
	StartRecordingAction(ApplicationManager* pApp);

	void ReadActionParameters();
	void Execute();
};

#endif