#include "RedoAction.h"
#include"../ApplicationManager.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagon.h"
#include"../Figures/CTriangle.h"
#include <sstream>
RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {}
void RedoAction::ReadActionParameters() {
    LoadString = pManager->TempLoadRedo();
}
void RedoAction::Execute() {
    ReadActionParameters();
    pManager->DeleteAllFigures();
    istringstream LoadFile(LoadString);
    int n = 0;
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