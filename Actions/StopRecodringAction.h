#pragma once
#ifndef STOP_RECORDING_ACTION-H
#define STOP_RECORDING_ACTION_H

#include "Action.h"

class StopRecordingAction : public Action
{
private:
public:
	StopRecordingAction(ApplicationManager* pApp);

	void ReadActionParameters();
	void Execute();
};

#endif