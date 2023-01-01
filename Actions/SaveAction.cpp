#include "SaveAction.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "..\ApplicationManager.h"
#include <fstream>
SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp) {
	file_name = "";
}
void SaveAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the name of the file to save to: ");
    file_name = pIn->GetString(pOut)+".txt";
	pOut->PrintMessage("File saved!");
}
void SaveAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream saveFile;
	saveFile.open(file_name);
	saveFile << CheckColor(pOut->getCrntDrawColor()) << " " << CheckColor(pOut->getCrntFillColor())<<endl;
	pManager->SaveAll(saveFile);
	saveFile.close();
}


string SaveAction::CheckColor(color x) {

	if (x == BLACK) {
		return "BLACK";
	}
	if (x == YELLOW) {
		return "YELLOW";
	}
	if (x == ORANGE) {
		return "ORANGE";
	}
	if (x == RED) {
		return "RED";
	}
	if (x == GREEN) {
		return "GREEN";
	}
	if (x == BLUE) {
		return "BLUE";
	}
	return "NO_COLOR";
}