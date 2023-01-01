#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "AddRectAction.h"
#include "AddCircAction.h"
#include "AddSqrAction.h"
#include "AddHexAction.h"
#include "AddTriAction.h"
#include "..\Figures\CCircle.h"
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

