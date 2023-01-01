#pragma once
#ifndef PLAY_RECORDING_ACTION-H
#define PLAY_RECORDING_ACTION_H

#include "Action.h"

class PlayRecordingAction : public Action
{
private:
public:
	PlayRecordingAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

#endif