#include "UndoAction.h"
#include"../ApplicationManager.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagon.h"
#include"../Figures/CTriangle.h"
#include <sstream>
UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp) {}
void UndoAction::ReadActionParameters() {
	LoadString = pManager->TempLoad();
}
void UndoAction::Execute() {
	ReadActionParameters();
	pManager->DeleteAllFigures();
	istringstream LoadFile(LoadString);
	int n;
	LoadFile >> n;
	CFigure* fig = NULL;
	string x;
	for (int i = 0; i < n; i++) {
		LoadFile >> x;
		if (x == "RECT") {
			fig = new CRectangle();
		}
		else if (x == "SQR") {
			fig = new CSquare();
		}
		else if (x == "CIRC") {
			fig = new CCircle();
		}
		else if (x == "HEX") {
			fig = new CHexagon();
		}
		else if (x == "TRIANG") {
			fig = new CTriangle();
		}
		fig->TempLoad(LoadFile);
		pManager->AddFigure(fig);
	}
}