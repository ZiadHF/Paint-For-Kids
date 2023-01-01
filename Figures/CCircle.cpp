#include "CCircle.h"
CCircle::CCircle()  
{
	 
}

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
string CCircle::TempSave() {
	return  "CIRC" + string(" ") + std::to_string(ID) + " " + std::to_string(Center.x) + " " + std::to_string(Center.y) + " " + std::to_string(Radius.x) + " " + std::to_string(Radius.y) + " " + CheckColor(FigGfxInfo.DrawClr) + " " + (FigGfxInfo.isFilled ? CheckColor(FigGfxInfo.FillClr) : "NO_FILL");

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
void CCircle::Load(ifstream& InFile) {
	int x;
	InFile >> x;
	ID = x;
	InFile >> x;
	Center.x = x;
	InFile >> x;
	Center.y = x;
	InFile >> x;
	Radius.x = x;
	InFile >> x;
	Radius.y = x;
	string y;
	InFile >> y;
	FigGfxInfo.DrawClr = StringToColor(y);
	InFile >> y;
	FigGfxInfo.FillClr = StringToColor(y);
	FigGfxInfo.isFilled = (FigGfxInfo.FillClr != HOTPINK);
}
void CCircle::MoveFigure(Point change) {
	Radius.x = change.x + (Radius.x - Center.x);
	Radius.y = change.y + (Radius.y - Center.y);
	Center.x = change.x;
	Center.y = change.y;
}