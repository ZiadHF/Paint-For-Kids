#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddCircAction.h"
#include"Actions/AddSqrAction.h"
#include"Actions/AddHexAction.h"
#include"Actions/AddTriAction.h"
#include"Figures/CCircle.h"
#include "PickAndHide.h"
#include "PickByFigFill.h"
#include "PickByFigure.h"
#include "PickByFill.h"

class CAll : public Action
{
public:
	CAll(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CAll();
};

