#include "CCircle.h"


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = count;
	Center = P1;
	Radius = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCir to draw a Circle on the screen	
	pOut->DrawCir(Center, Radius, FigGfxInfo, Selected);

}
void CCircle::Save(ofstream& OutFile) {
	OutFile << "CIRC" << " " << ID << " " << Center.x << " " << Center.y << " " << Radius.x << " " << Radius.y << " " << CheckColor(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? CheckColor(FigGfxInfo.FillClr) : "NO_FILL") << endl;

}
//Printing Circle information in status bar
void CCircle::PrintInfo(Output* pOut) {
	string data1, data2;
	int rcircle = sqrt(pow((Radius.x - Center.x), 2) + pow((Radius.y - Center.y), 2));
	string dataid = "ID: " + to_string(ID);
	data1 = " Center: (" + to_string(Center.x) + ',' + to_string(Center.y) + ')';
	data2 = " Radius= " + to_string(rcircle);
	pOut->PrintMessage("Circle " + dataid + data1 + data2);
}
bool CCircle::Contains(Point test) {
	double dtest, rcircle;
	rcircle = pow((Radius.x - Center.x), 2) + pow((Radius.y - Center.y), 2);
	dtest = pow((test.x - Center.x), 2) + pow((test.y - Center.y), 2);
	if (dtest <= rcircle)
		return true;
	else
		return false;
}
void CCircle::MoveFigure(Point change) {
	Radius.x = change.x + (Radius.x - Center.x);
	Radius.y = change.y + (Radius.y - Center.y);
	Center.x = change.x;
	Center.y = change.y;
}