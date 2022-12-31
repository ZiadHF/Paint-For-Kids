#include "LoadAction.h"
#include"../ApplicationManager.h"
#include <fstream>
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagon.h"
#include"../Figures/CTriangle.h"
#include "../GUI/UI_Info.h"
LoadAction::LoadAction(ApplicationManager* pManager) :Action(pManager) {
	FileName = "";
}

void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the name of the file to load (name without extension): ");
	FileName = pIn->GetString(pOut) + ".txt";
	ifstream LoadFile(FileName);
	LoadFile.is_open() ? pOut->PrintMessage("File loaded!") : pOut->PrintMessage("File doesn't exist!");
	LoadFile.close();
}
void LoadAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ifstream LoadFile(FileName);
	if (!LoadFile.is_open()) {
		return;
	}
	string x;

	LoadFile >> x;
	UI.DrawColor = CheckColor(x);
	LoadFile >> x;
	UI.FillColor = CheckColor(x);
	int n;
	LoadFile >> n;

	CFigure* fig = nullptr;
	pManager->setSelectedFigure(NULL);
	pManager->DeleteAllFigures();
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
		fig->Load(LoadFile);
		pManager->AddFigure(fig);
	}
	LoadFile.close();
}

color LoadAction::CheckColor(string x) {
	if (x == "BLACK") {
		return BLACK;
	}
	if (x == "YELLOW") {
		return YELLOW;
	}
	if (x == "ORANGE") {
		return ORANGE;
	}
	if (x == "RED") {
		return RED;
	}
	if (x == "GREEN") {
		return GREEN;
	}
	if (x == "BLUE") {
		return BLUE;
	}
	return LIMEGREEN;
}

