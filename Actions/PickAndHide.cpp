#include "PickAndHide.h"
#include "ApplicationManager.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) : Action(pApp) {
	bool IsPicked = false;
}

void PickAndHide::ReadActionParameters() {

}

void PickAndHide::Execute() {
	ReadActionParameters();
	IsPicked = true;
}

PickAndHide::~PickAndHide() {

}
